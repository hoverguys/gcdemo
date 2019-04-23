#include "pchheader.h"
#include "VorbisResource.h"

#include "audio/VorbisTrack.h"

void VorbisResource::Initialize() {
    auto s = eastl::make_shared<VorbisTrack>(data);
    internal = s;
}

eastl::shared_ptr<VorbisTrack> VorbisResource::Load() {
    return internal;
}
