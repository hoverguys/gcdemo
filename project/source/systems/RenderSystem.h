#pragma once

#include "../pchheader.h"

#include "../components/Light.h"
#include "../components/Camera.h"
#include "../components/Transform.h"
#include "../components/Renderable.h"
#include "../math/Matrix.h"

namespace cp = Components;

class RenderSystem {
public:
	static void Initialize(const u8 lightCount);
	static void Destroy();
	static void Setup3DCamera(cp::Camera& camera);
	static bool SetupLight(const Matrix& cameraMtx, const cp::DirectionalLight& light, const cp::Transform& transform, u8 lightId);
	static void Render(const Matrix& cameraMtx, const cp::Renderable& renderable, cp::Transform& transform);

private:
	static u8 maxLights;
	static GXLightObj* lightObjects;
};