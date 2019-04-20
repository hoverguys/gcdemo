#include "Script.h"

#include "components/AlphaFade.h"
#include "components/Sprite.h"

#include "systems/AudioSystem.h"

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
	});
}

void FadeOut::run(ex::EntityManager& es, ex::EventManager& events) const {
	u64 start = gettime();
	es.each<cp::AlphaFade, cp::Sprite>([&](ex::Entity entity, cp::AlphaFade& fade, cp::Sprite& sprite) {
		fade.direction = cp::AlphaFade::FadeDirection::FadeOut;
		fade.startTime = start;
		fade.duration = duration;
		fade.done = false;
	});
}

void PlayMusic::run(ex::EntityManager& es, ex::EventManager& events) const {
	events.emit<AudioEvent>(AudioEvent{AudioEvent::Type::PlayMusic});
}

void StopMusic::run(ex::EntityManager& es, ex::EventManager& events) const {
	events.emit<AudioEvent>(AudioEvent{AudioEvent::Type::StopMusic});
}