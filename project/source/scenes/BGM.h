#pragma once
#include "../pchheader.h"
#include "Scene.h"

class BGM : public Scene {
public:
	void Load() override;
	void Run(float dt) override;
};
