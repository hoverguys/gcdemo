#pragma once
#include "../pchheader.h"
#include "../systems/SceneSystem.h"

namespace ex = entityx;

// Create empty type to act as marker for entities in the scene
#define MARKER(marker) \
	struct marker {}

// Wrap templated methods with a specified marker
#define SCENE(marker)                                                                \
	static ex::Entity create(bool tag = true) { return Scene::create<marker>(tag); } \
	static void unload() { Scene::unload<marker>(); }

class Scene {
public:
	template <typename T>
	static ex::Entity create(bool tag = true) {
		auto entity = SceneSystem::manager->entities.create();
		if (tag) {
			entity.assign<T>();
		}
		return entity;
	}

	template <typename S>
	static std::shared_ptr<S> system() {
		return SceneSystem::manager->systems.system<S>();
	}

	template <typename T>
	static void unload() {
		SceneSystem::manager->entities.each<T>([](ex::Entity entity, T& marker) { entity.destroy(); });
	}

private:
	Scene() = delete;
};
