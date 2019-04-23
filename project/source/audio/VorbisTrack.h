#pragma once

namespace Components {
struct OggPlayer;
}

class VorbisTrack {
public:
    VorbisTrack(eastl::span<char> span) : data(span) {}

protected:
    friend class VorbisResource;
    friend class Components::OggPlayer;

    eastl::span<char> data;
};
