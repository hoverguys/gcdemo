#pragma once
#include "../pchheader.h"

namespace ex = entityx;

class SceneSystem {
public:
	static void initialize(ex::EntityX* manager) { SceneSystem::manager = manager; }
	static ex::EntityX* manager;

protected:
	friend class Scene;
};
