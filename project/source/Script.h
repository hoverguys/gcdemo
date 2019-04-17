#pragma once
#include "pchheader.h"
#include "systems/SceneSystem.h"

struct ScriptEvent {
	virtual void run(ex::EventManager& events) const {};
};

typedef std::pair<u64, ScriptEvent> ScriptEventEntry;

template <class S>
struct LoadSceneEvent : ScriptEvent {
	void run(ex::EventManager& events) const override { S::load(); }
};

template <class S>
struct UnloadSceneEvent : ScriptEvent {
	void run(ex::EventManager& events) const override { S::unload(); }
};

class time_cmp {
public:
	bool operator()(ScriptEventEntry a, ScriptEventEntry b) const { return a.first < b.first; }
};

class Script {
public:
	void at(u64 time, ScriptEvent event);
	std::priority_queue<ScriptEventEntry, std::vector<ScriptEventEntry>, time_cmp> events;
};
