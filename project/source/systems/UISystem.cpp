#include "UISystem.h"

#include "../rendering/Graphics.h"

#include "../components/AlphaFade.h"
#include "../components/Sprite.h"
#include "../components/Transform.h"

#include <ogc/lwp_watchdog.h>

namespace cp = Components;

void UISystem::update(ex::EntityManager& es, ex::EventManager& events, ex::TimeDelta dt) {
	// Setup 2D rendering
	Setup2D();

	// Update fading
	es.each<cp::AlphaFade, cp::Sprite>([&](ex::Entity entity, cp::AlphaFade& fade, cp::Sprite& sprite) {
		// This entity isn't fading
		if (fade.done) {
			return;
		}

		auto now = gettime();
		auto end = fade.startTime + fade.duration;
		if (now > end) {
			sprite.material->uniforms.color0.a = fade.direction == cp::AlphaFade::FadeDirection::FadeOut ? 0xff : 0;
			fade.done = true;
			return;
		}

		u8 progress = (u8)((now-fade.startTime)*0xff/(end-fade.startTime));
		sprite.material->uniforms.color0.a = fade.direction == cp::AlphaFade::FadeDirection::FadeOut ? progress : 0xff - progress;
		std::printf("Fade progress: %x (%u)\n", progress, progress);
	});

	// Sort sprites on depth
	std::priority_queue<
		SortedSprite,
		std::vector<SortedSprite>,
		std::greater<SortedSprite>
		> orderedSprites;

	for (ex::Entity entity : es.entities_with_components<cp::Transform, cp::Sprite>()) {
		ex::ComponentHandle<cp::Transform> transform = entity.component<cp::Transform>();
		orderedSprites.push(std::make_pair(transform->position.z, entity));
	}

	// Render sorted sprites
	while(!orderedSprites.empty()) {
		auto entity = orderedSprites.top().second;
		auto transform = *entity.component<cp::Transform>();
		auto sprite = *entity.component<cp::Sprite>();

		const Matrix& spriteMtx = transform.GetMatrix();

		// Positional matrix with camera
		Mtx nativeTemp;
		spriteMtx.ToNative(nativeTemp);
		GX_LoadPosMtxImm(nativeTemp, GX_PNMTX0);

		auto material = sprite.material;
		if (material) {
			auto shader = material->shader;
			if (shader) {
				// Setup shader
				shader->Use();

				// Setup shader uniforms
				auto settings = material->uniforms;
				GX_SetChanAmbColor(GX_COLOR0A0, GXColor{0x00, 0x00, 0x00, 0x00});
				GX_SetChanMatColor(GX_COLOR0A0, settings.color0);
				GX_SetChanMatColor(GX_COLOR1A1, settings.color1);
			} else {
				Shader::DefaultUnlit();
			}

			auto textures = material->textures;
			for (unsigned int i = 0; i < textures.size(); i++) {
				if (textures[i]) {
					textures[i]->Bind(i);
				}
			}
		}

		auto uv = sprite.bounds.Bounds();

		GX_Begin(GX_QUADS, GX_VTXFMT0, 4);

		/* Top left */
		GX_Position2f32(0, 0);
		GX_TexCoord2f32(uv.first.x, uv.first.y);

		/* Bottom left */
		GX_Position2f32(0, sprite.size.y);
		GX_TexCoord2f32(uv.first.x, uv.second.y);

		/* Bottom right */
		GX_Position2f32(sprite.size.x, sprite.size.y);
		GX_TexCoord2f32(uv.second.x, uv.second.y);

		/* Top right */
		GX_Position2f32(sprite.size.x, 0);
		GX_TexCoord2f32(uv.second.x, uv.first.y);

		GX_End();

		orderedSprites.pop();
	};
}

void UISystem::Setup2D() {
	// Use orthogonal
	Graphics::Set2DMode();

	// Use identity matrix for normals
	Mtx dummy;
	guMtxIdentity(dummy);
	GX_LoadNrmMtxImm(dummy, GX_PNMTX0);

	// Setup vertex descriptors to use immediate mode
	GX_ClearVtxDesc();
	GX_SetVtxDesc(GX_VA_POS, GX_DIRECT);
	GX_SetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_F32, 0);
	GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
}