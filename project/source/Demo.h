#pragma once

class Scene;

class Demo {
private:
    u64 startTime = 0;

public:
    explicit Demo();
    void init();
    void update(float dt);

    Scene* currentScene;
};