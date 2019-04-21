#include "RenderSystem.h"

#include "../math/Math.h"

u8 RenderSystem::maxLights = 0;
GXLightObj* RenderSystem::lightObjects = nullptr;

void RenderSystem::Initialize(const u8 lightCount) {
	if (lightCount < 0 || lightCount > 8) {
		abort();
	}

	maxLights = lightCount;
	lightObjects = (GXLightObj*) memalign(32, sizeof(GXLightObj) * lightCount);
}

void RenderSystem::Destroy() {
	free(lightObjects);
}

void RenderSystem::Setup3DCamera(cp::Camera& camera) {
	GX_SetScissor(camera.viewport.offsetLeft, camera.viewport.offsetTop, camera.viewport.width, camera.viewport.height);
	GX_SetViewport(camera.viewport.offsetLeft, camera.viewport.offsetTop, camera.viewport.width, camera.viewport.height,
				   0, 1);
	GX_LoadProjectionMtx(camera.perspectiveMtx, GX_PERSPECTIVE);
}

bool RenderSystem::SetupLight(const Matrix& cameraMtx, const cp::DirectionalLight& light, const cp::Transform& transform, u8 lightId) {
	if (lightId < 0 || lightId >= maxLights) {
		return false;
	}

	auto lightMask = 1 << lightId;
	auto& lightObject = lightObjects[lightId];

	light.Setup(cameraMtx, transform, lightObject);
	GX_LoadLightObj(&lightObject, lightMask);

	return true;
}

void RenderSystem::Render(const Matrix& cameraMtx, const cp::Renderable& renderable, cp::Transform& transform) {
	const Matrix& modelMtx = transform.GetMatrix();

	// Positional matrix with camera
	Mtx nativeTemp;
	const Matrix modelviewMtx = cameraMtx * modelMtx;
	modelviewMtx.ToNative(nativeTemp);
	GX_LoadPosMtxImm(nativeTemp, GX_PNMTX0);

	// Normals
	Matrix modelviewInverseMtx = modelviewMtx.Inversed();
	modelviewInverseMtx.Transpose();
	modelviewInverseMtx.ToNative(nativeTemp);
	GX_LoadNrmMtxImm(nativeTemp, GX_PNMTX0);

	auto material = renderable.material;
	if (material != nullptr) {
		auto shader = material->shader;
		if (shader != nullptr) {
			// Setup shader
			shader->Use();

			// Setup shader uniforms
			auto settings = material->uniforms;
			GX_SetChanAmbColor(GX_COLOR0A0, GXColor{0x00, 0x00, 0x00, 0x00});
			GX_SetChanMatColor(GX_COLOR0A0, settings.color0);
			GX_SetChanMatColor(GX_COLOR1A1, settings.color1);
		} else {
			Shader::Default();
		}

		auto textures = material->textures;
		for (unsigned int i = 0; i < textures.size(); i++) {
			if (textures[i]) {
				textures[i]->Bind(i);
			}
		}
	}

	renderable.mesh->Render();
}
