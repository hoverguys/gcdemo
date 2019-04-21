#pragma once
#include "../pchheader.h"
#include "Scene.h"

class DemoScene : public Scene {
public:
	void Load() override;
	void Run(float dt) override;
};
