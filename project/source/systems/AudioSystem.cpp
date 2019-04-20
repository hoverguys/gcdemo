#include "AudioSystem.h"

#include "../components/OggPlayer.h"

namespace cp = Components;

void AudioSystem::configure(ex::EventManager& event_manager) {
	event_manager.subscribe<AudioEvent>(*this);
}

void AudioSystem::receive(const AudioEvent& event) {
	switch (event.type) {
	case AudioEvent::Type::PlayMusic: playingMusic = true; break;
	case AudioEvent::Type::StopMusic: playingMusic = false; break;
	}
}

void AudioSystem::update(ex::EntityManager& es, ex::EventManager& events, ex::TimeDelta dt) {
	// Terrible hack but I don't want to refactor oggplayer to play more than one tune at a time, so who cares for now
	es.each<cp::OggPlayer>([&](ex::Entity entity, cp::OggPlayer& player) {
		if (player.playing && !playingMusic) {
			player.Stop();
		}
		if (!player.playing && playingMusic) {
			player.Play();
		}
	});
}
