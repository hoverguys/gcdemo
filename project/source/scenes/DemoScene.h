#pragma once
#include "../pchheader.h"
#include "Scene.h"

struct DemoSceneMarker {};
struct DemoScene : public Scene<DemoSceneMarker> {
public:
    static void load();
};