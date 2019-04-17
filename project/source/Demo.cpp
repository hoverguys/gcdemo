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

namespace bh = Behaviours;

Demo::Demo() {
	Script script;
	script.at(0, LoadSceneEvent<DemoScene>());
	script.at(10, UnloadSceneEvent<DemoScene>());

	systems.add<BehaviourSystem<bh::Hovercraft>>();
	systems.add<PhysicsSystem>();
	systems.add<RenderSystem>();
	systems.add<UISystem>();
	systems.add<TimelineSystem>(script);
	systems.configure();
}

void Demo::init() {
	SceneSystem::initialize(this);
	std::printf("Loading Demo scene\n");
	ResourceLoader::PrintUsage();
}

void Demo::update(ex::TimeDelta dt) {
	systems.update_all(dt);
	systems.update<TimelineSystem>(dt);
}
