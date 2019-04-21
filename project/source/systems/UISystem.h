#pragma once

#include "../components/Sprite.h"
#include "../components/Transform.h"

namespace cp = Components;

class UISystem {
public:
	static void Setup2DCamera();
	static void Render(const cp::Sprite& sprite, cp::Transform& transform);
};