#include "Script.h"

#include "components/Sprite.h"
#include "components/AlphaFade.h"

namespace cp = Components;

void Script::at(u64 at, std::shared_ptr<ScriptEvent> event) {
	events.push(ScriptEventEntry(at, event));
}

void FadeIn::run(ex::EntityManager& es, ex::EventManager& events) const {
	u64 start = gettime();
	es.each<cp::AlphaFade, cp::Sprite>([&](ex::Entity entity, cp::AlphaFade& fade, cp::Sprite& sprite) {
		fade.direction = cp::AlphaFade::FadeDirection::FadeIn;
		fade.startTime = start;
		fade.duration = duration;
		fade.done = false;
		std::printf("One sprite ready to fade\n");
	});
}

void FadeOut::run(ex::EntityManager& es, ex::EventManager& events) const {
	//todo
}