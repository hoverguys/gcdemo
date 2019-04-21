#pragma once

#include "Scene.h"
#include "../components/Sprite.h"
#include "../components/Transform.h"

class DemoScene : public Scene {
public:
	DemoScene() {};
	void Load() override;
	void Run(float dt) override;

private:
	cp::Transform* backgroundTransform;
	cp::Sprite* backgroundSprite;
};
