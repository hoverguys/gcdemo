#pragma once
#include "pchheader.h"
#include "scenes/Scene.h"

class Demo {
private:
	u64 startTime = 0;
public:
	explicit Demo();
	void init();
	void update(float dt);

	Scene* currentScene;
};