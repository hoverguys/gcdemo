#pragma once
#include "../pchheader.h"
#include "Scene.h"

MARKER(FadeScreenMarker);

class FadeScreen : public Scene {
public:
	SCENE(FadeScreenMarker);

	static void load();
};
