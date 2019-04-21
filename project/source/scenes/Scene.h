#pragma once
#include "../pchheader.h"
#include "../systems/SceneSystem.h"


class Scene {
public:
	virtual void Load() = 0;
	virtual void Run(float dt) = 0;
private:
	Scene() = delete;
};
