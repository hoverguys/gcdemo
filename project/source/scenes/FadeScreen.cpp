#include "FadeScreen.h"

#include "../components/Sprite.h"
#include "../components/AlphaFade.h"
#include "../components/Transform.h"

#include "../rendering/Material.h"
#include "../resources/ResourceLoader.h"
#include "../resources/ShaderResource.h"

namespace cp = Components;

void FadeScreen::load() {
    // Full-sceen black sprite that *should* cover everything else
	auto fader = create();
	auto fadeShaderBin = ResourceLoader::Load<ShaderResource>("shaders/fade.tev");
	auto fadeShader = fadeShaderBin->Load();
	auto fadeMat = std::make_shared<Material>();
	//fadeMat->textures = {};
	fadeMat->shader = fadeShader;
	fadeMat->uniforms.color0 = GXColor{0, 0, 0, 0xff};
	fader.assign<cp::Transform>(cp::Transform({30, 0, -1}));
	fader.assign<cp::Sprite>(cp::Sprite(Vector2D(640, 480), fadeMat, Rect(0, 0, 1, 1))); // I KNOW I KNOW, Res needs to be tweaked to be fullscreen
	fader.assign<cp::AlphaFade>(); // Add alpha fading
    std::printf("Loaded fade screen\n");
}