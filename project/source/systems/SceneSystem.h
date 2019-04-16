#pragma once
#include "../pchheader.h"

namespace ex = entityx;

typedef void* ScenePtr;

struct SceneAction {
	enum class Command {
		LoadScene,
		FadeIn,
		FadeOut,
		UnloadScene
	};

	Command command;
	std::string sceneID;
};

class SceneSystem {
public:
	static void initialize(ex::EntityX* manager) {
		SceneSystem::manager = manager;
	}
	static ex::EntityX* manager;
protected:
	template<typename T>
	friend class Scene;

	struct SceneEntry {
		ScenePtr scene;
		bool active;
	};

	std::map<std::string, SceneEntry> scenes;

	void receive(const SceneAction& cmd);
};