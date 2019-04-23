#pragma once

class Scene {
public:
    virtual void Load() = 0;
    virtual void Run(float dt) = 0;
};
