#pragma once

#include "Scene.h"

class BGM : public Scene {
public:
    void Load() override;
    void Run(float dt) override;
};
