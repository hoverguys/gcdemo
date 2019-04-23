#include "pchheader.h"
#include "Demo.h"

#include "resources/ResourceLoader.h"
#include "scenes/DemoScene.h"
#include "scenes/Scene.h"
#include "systems/RenderSystem.h"

Demo::Demo() {}

void Demo::init() {
    RenderSystem::Initialize(8);
    ResourceLoader::PrintUsage();

    currentScene = new DemoScene();
    currentScene->Load();
}

void Demo::update(float dt) {
    if (currentScene != nullptr) {
        currentScene->Run(dt);
    }
}
