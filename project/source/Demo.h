#pragma once
#include "pchheader.h"
#include <ogc/lwp_watchdog.h>

namespace ex = entityx;

class Demo : public ex::EntityX {
private:
	u64 startTime = 0;
public:
	explicit Demo();
	void init();
	void update(ex::TimeDelta dt);
};