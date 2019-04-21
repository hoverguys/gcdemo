#include "DemoScene.h"

#include "../components/Sprite.h"
#include "../components/Transform.h"

#include "../rendering/Material.h"
#include "../resources/MeshResource.h"
#include "../resources/ResourceLoader.h"
#include "../resources/ShaderResource.h"
#include "../resources/TextureResource.h"

namespace cp = Components;

void DemoScene::Load() {
    // Background sprite
	auto backgroundTex = ResourceLoader::Load<TextureResource>("sprites/desire.png")->Load();
	auto backgroundMat = std::make_shared<Material>();
	backgroundMat->textures = {backgroundTex};
	backgroundMat->shader = ResourceLoader::Load<ShaderResource>("shaders/test.tev")->Load();
	backgroundMat->uniforms.color0 = GXColor{0, 0, 0, 0xff};

	auto backgroundTransform = cp::Transform({0, 0, -2});
	auto backgroundSprite = cp::Sprite(Vector2D(640, 480), backgroundMat, Rect(0, 0, 1, 1));
    std::printf("Loaded DemoScene\n");
}