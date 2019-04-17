#pragma once
#include "../pchheader.h"

#include "../Script.h"

namespace ex = entityx;

class TimelineSystem : public ex::System<TimelineSystem> {
public:
	TimelineSystem(Script& script);
	void update(ex::EntityManager& es, ex::EventManager& events, ex::TimeDelta dt) override;

protected:
	Script& tlScript;
	u64 startTime = 0;
};
