#include "Demo.h"

#include "resources/ResourceLoader.h"

#include "systems/AudioSystem.h"
#include "systems/BehaviourSystem.h"
#include "systems/PhysicsSystem.h"
#include "systems/RenderSystem.h"
#include "systems/SceneSystem.h"
#include "systems/TimelineSystem.h"
#include "systems/UISystem.h"

#include "scenes/BGM.h"
#include "scenes/DemoScene.h"
#include "scenes/FadeScreen.h"

Demo::Demo() {
	auto script = std::make_shared<Script>();
	script->at(0, std::make_shared<LoadSceneEvent<BGM>>());
	script->at(0, std::make_shared<LoadSceneEvent<FadeScreen>>());
	script->at(0, std::make_shared<LoadSceneEvent<DemoScene>>());
	script->at(sec(0), std::make_shared<FadeIn>(sec(2)));
	script->at(sec(8), std::make_shared<FadeOut>(sec(2)));
	script->at(sec(10), std::make_shared<UnloadSceneEvent<DemoScene>>());
	script->at(sec(1), std::make_shared<PlayMusic>());

	systems.add<AudioSystem>();
	systems.add<RenderSystem>();
	systems.add<UISystem>();
	systems.add<TimelineSystem>(script);
	systems.configure();
}

void Demo::init() {
	SceneSystem::initialize(this);
	ResourceLoader::PrintUsage();
}

void Demo::update(ex::TimeDelta dt) {
	systems.update<TimelineSystem>(dt);
	systems.update<AudioSystem>(dt);
	systems.update<RenderSystem>(dt);
	systems.update<UISystem>(dt);
}
