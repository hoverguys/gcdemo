#pragma once

#include "scenes/Scene.h"

namespace Components {
class Transform;
class Sprite;
} // namespace Components

class DemoScene : public Scene {
public:
    DemoScene(){};
    void Load() override;
    void Run(float dt) override;

private:
    cp::Transform* backgroundTransform;
    cp::Sprite* backgroundSprite;
};
