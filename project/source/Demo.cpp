#include "Demo.h"

#include "resources/ResourceLoader.h"

#include "behaviours/Hovercraft.h"
#include "systems/BehaviourSystem.h"
#include "systems/PhysicsSystem.h"
#include "systems/RenderSystem.h"
#include "systems/SceneSystem.h"
#include "systems/UISystem.h"

#include "scenes/DemoScene.h"

namespace bh = Behaviours;

Demo::Demo() {
	systems.add<BehaviourSystem<bh::Hovercraft>>();
	systems.add<PhysicsSystem>();
	systems.add<RenderSystem>();
	systems.add<UISystem>();
	systems.configure();
	startTime = gettime();
}

void Demo::init() {
	SceneSystem::initialize(this);
	std::printf("Loading Demo scene\n");
	DemoScene::load();
	ResourceLoader::PrintUsage();
}

void Demo::update(ex::TimeDelta dt) {
	auto currentTime = gettime() - startTime;

	systems.update<BehaviourSystem<bh::Hovercraft>>(dt);
	systems.update<PhysicsSystem>(dt);
	systems.update<RenderSystem>(dt);
	systems.update<UISystem>(dt);
}