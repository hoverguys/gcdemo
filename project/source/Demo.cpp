#include "Demo.h"

#include "resources/ResourceLoader.h"

#include "behaviours/Hovercraft.h"
#include "systems/BehaviourSystem.h"
#include "systems/PhysicsSystem.h"
#include "systems/RenderSystem.h"
#include "systems/SceneSystem.h"
#include "systems/TimelineSystem.h"
#include "systems/UISystem.h"

#include "scenes/DemoScene.h"
#include "scenes/FadeScreen.h"

namespace bh = Behaviours;

Demo::Demo() {
	auto script = std::make_shared<Script>();
	script->at(0, std::make_shared<LoadSceneEvent<DemoScene>>());
	script->at(0, std::make_shared<LoadSceneEvent<FadeScreen>>());
	script->at(sec(2), std::make_shared<FadeIn>());
	script->at(sec(10), std::make_shared<UnloadSceneEvent<DemoScene>>());

	systems.add<BehaviourSystem<bh::Hovercraft>>();
	systems.add<PhysicsSystem>();
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
	systems.update<BehaviourSystem<bh::Hovercraft>>(dt);
	systems.update<PhysicsSystem>(dt);
	systems.update<RenderSystem>(dt);
	systems.update<UISystem>(dt);
}
