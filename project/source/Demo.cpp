#include "Demo.h"

#include "resources/ResourceLoader.h"

#include "systems/RenderSystem.h"
#include "systems/SceneSystem.h"
#include "systems/UISystem.h"

#include "scenes/BGM.h"
#include "scenes/DemoScene.h"

Demo::Demo() {
}

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
