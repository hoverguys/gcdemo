#pragma once
#include "../pchheader.h"

namespace ex = entityx;

struct AudioEvent {
	enum class Type { PlayMusic, StopMusic } type;
};

class AudioSystem : public ex::System<AudioSystem>, public ex::Receiver<AudioSystem> {
protected:
	bool playingMusic;

public:
	void configure(ex::EventManager& event_manager);
	void receive(const AudioEvent& event);
	void update(ex::EntityManager& es, ex::EventManager& events, ex::TimeDelta dt) override;
};
