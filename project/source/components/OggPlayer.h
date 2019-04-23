#pragma once

#include "../audio/VorbisTrack.h"

namespace Components {
struct OggPlayer {
    eastl::shared_ptr<VorbisTrack> track;
    bool playing = false;

    OggPlayer(eastl::shared_ptr<VorbisTrack> track) : track(track) {}

    void Play(int from = 0);
    void Stop();
    s32 Position();
};
} // namespace Components
