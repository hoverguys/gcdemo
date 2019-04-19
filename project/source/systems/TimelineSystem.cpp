#include "TimelineSystem.h"
#include <ogc/lwp_watchdog.h>

TimelineSystem::TimelineSystem(std::shared_ptr<Script> script) : tlScript(script) {
	startTime = gettime();
}

void TimelineSystem::update(ex::EntityManager& es, ex::EventManager& events, ex::TimeDelta dt) {
	// TODO Take time from song player entity
	auto currentTime = gettime() - startTime;

	// No events left? nothing to do
	if (tlScript->events.empty()) {
		return;
	}
		
	// Get next event
	auto nextEventTime = tlScript->events.top().first;

	// Check if there are one or more events that are due to be run
	while (currentTime >= nextEventTime) {
		std::printf("Running next event is scheduled at %llums | Now it's %llums\n", ticks_to_millisecs(nextEventTime), ticks_to_millisecs(currentTime));
		// Run event
		tlScript->events.top().second->run(es, events);
		// Take event out of the queue
		tlScript->events.pop();
		// If no more events are available, exit early
		if (tlScript->events.empty()) {
			break;
		}
		// Get next event
		auto nextEvent = tlScript->events.top();
		// Use its time as the next milestone
		nextEventTime = nextEvent.first;
	}
}
