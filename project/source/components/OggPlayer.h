#pragma once

#include "../pchheader.h"

#include "../audio/VorbisTrack.h"

namespace Components {
struct OggPlayer {
	std::shared_ptr<VorbisTrack> track;
	bool playing = false;

	OggPlayer(std::shared_ptr<VorbisTrack> track) : track(track) {}

	void Play(int from = 0);
	void Stop();
	s32 Position();
};
} // namespace Components