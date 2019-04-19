#include "DemoScene.h"

#include "../components/Sprite.h"
#include "../components/Transform.h"

#include "../systems/BehaviourSystem.h"

#include "../rendering/Material.h"
#include "../resources/MeshResource.h"
#include "../resources/ResourceLoader.h"
#include "../resources/ShaderResource.h"
#include "../resources/TextureResource.h"

namespace cp = Components;

void DemoScene::load() {
    // Timer sprite
	auto timer = create();
	auto timerTexRes = ResourceLoader::Load<TextureResource>("generated/timerfont.png");
	auto timerTex = timerTexRes->Load();
	auto fontShaderBin = ResourceLoader::Load<ShaderResource>("shaders/font.tev");
	auto fontShader = fontShaderBin->Load();
	auto timerMat = std::make_shared<Material>();
	timerMat->textures = {timerTex};
	timerMat->shader = fontShader;
	timerMat->uniforms.color0 = GXColor{0xff, 0, 0, 0xff};
	// auto timerAtlasRes = ResourceLoader::Load<AtlasResource>("generated/timer.png.atlas");
	// auto timerAtlas = timerAtlasRes->Load();
	timer.assign<cp::Transform>(cp::Transform({10, 10, -1}));
	timer.assign<cp::Sprite>(cp::Sprite(Vector2D(128, 128), timerMat, Rect(0, 0, 1, 1))); // TODO Make Atlas work (also nicer to use)
    std::printf("Loaded DemoScene\n");
}