#include "DemoScene.h"
#include "pchheader.h"

#include "components/Sprite.h"
#include "components/Transform.h"
#include "math/Vector2d.h"
#include "rendering/Material.h"
#include "resources/ResourceLoader.h"
#include "resources/ShaderResource.h"
#include "resources/TextureResource.h"

#include "systems/UISystem.h"

void DemoScene::Load() {
    // Background sprite
    auto backgroundTex = ResourceLoader::Load<TextureResource>("sprites/desire.png")->Load();
    auto backgroundMat = eastl::make_shared<Material>();
    backgroundMat->textures = {backgroundTex};
    backgroundMat->shader = ResourceLoader::Load<ShaderResource>("shaders/test.tev")->Load();
    backgroundMat->uniforms.color0 = GXColor{0, 0, 0, 0xff};

    backgroundTransform = new cp::Transform({0, 0, -2});
    backgroundSprite = new cp::Sprite(Vector2D(640, 480), backgroundMat, Rect(0, 0, 1, 1));
}

void DemoScene::Run(float dt) {
    UISystem::Setup2DCamera();
    UISystem::Render(*backgroundSprite, *backgroundTransform);
}
