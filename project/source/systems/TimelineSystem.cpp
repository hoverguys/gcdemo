#include "TimelineSystem.h"
#include <ogc/lwp_watchdog.h>

TimelineSystem::TimelineSystem(Script& script) : tlScript(script) {
	startTime = gettime();
}

void TimelineSystem::update(ex::EntityManager& es, ex::EventManager& events, ex::TimeDelta dt) {
	// TODO Take time from song player entity
	auto currentTime = gettime() - startTime;

	// Print next event
	auto next = tlScript.events.top().first;
	std::printf("Next event is at %llu | Now it's %llu\n", next, currentTime);

	while (currentTime > next && !tlScript.events.empty()) {
		tlScript.events.top().second.run(events);
		tlScript.events.pop();
		next = tlScript.events.top().first;
	}
}
