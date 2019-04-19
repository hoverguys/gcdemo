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
    // Background sprite
	auto background = create();
	auto backgroundTex = ResourceLoader::Load<TextureResource>("textures/testmap.png")->Load();
	auto backgroundMat = std::make_shared<Material>();
	backgroundMat->textures = {backgroundTex};
	backgroundMat->uniforms.color0 = GXColor{0xff, 0, 0, 0xff};

	background.assign<cp::Transform>(cp::Transform({0, 0, -2}));
	background.assign<cp::Sprite>(cp::Sprite(Vector2D(640, 480), backgroundMat, Rect(0, 0, 1, 1)));
    std::printf("Loaded DemoScene\n");
}