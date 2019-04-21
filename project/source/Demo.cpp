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
}

void Demo::update(float dt) {

}
