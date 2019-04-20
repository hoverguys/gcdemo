#include "OggPlayer.h"

#include "../libs/oggplayer/oggplayer.h"

namespace Components {

void OggPlayer::Play(int from) {
	PlayOgg(track->data, track->size, from, OGG_INFINITE_TIME);
	playing = true;
}

void OggPlayer::Stop() {
	StopOgg();
	playing = false;
}

s32 OggPlayer::Position() {
	return GetTimeOgg();
}

} // namespace Components