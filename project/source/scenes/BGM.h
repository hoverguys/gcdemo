#pragma once
#include "../pchheader.h"
#include "Scene.h"

MARKER(BGMMarker);

class BGM : public Scene {
public:
	SCENE(BGMMarker);

	static void load();
};
