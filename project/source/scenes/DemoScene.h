#pragma once
#include "../pchheader.h"
#include "Scene.h"

MARKER(DemoSceneMarker);

class DemoScene : public Scene {
public:
	SCENE(DemoSceneMarker);

	static void load();
};
