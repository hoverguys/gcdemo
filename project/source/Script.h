#pragma once
#include "pchheader.h"

#include "systems/SceneSystem.h"

#include <ogc/lwp_watchdog.h>

#define sec(x) secs_to_ticks(x)
#define min(x) sec(60*x)
#define ms(x) millisecs_to_ticks(x)

struct ScriptEvent {
	virtual void run(ex::EntityManager& es, ex::EventManager& events) const = 0;
};

typedef std::pair<u64, std::shared_ptr<ScriptEvent>> ScriptEventEntry;

template <class S>
struct LoadSceneEvent : ScriptEvent {
	void run(ex::EntityManager& es, ex::EventManager& events) const override { S::load(); }
};

template <class S>
struct UnloadSceneEvent : ScriptEvent {
	void run(ex::EntityManager& es, ex::EventManager& events) const override { S::unload(); }
};

struct FadeIn : ScriptEvent {
	u32 duration = sec(1);
	void run(ex::EntityManager& es, ex::EventManager& events) const override;
};

struct FadeOut : ScriptEvent {
	u32 duration = sec(1);
	void run(ex::EntityManager& es, ex::EventManager& events) const override;
};

class time_cmp {
public:
	bool operator()(ScriptEventEntry& a, ScriptEventEntry& b) const { return a.first > b.first; }
};

class Script {
public:
	void at(u64 time, std::shared_ptr<ScriptEvent> event);
	std::priority_queue<ScriptEventEntry, std::vector<ScriptEventEntry>, time_cmp> events;
};
