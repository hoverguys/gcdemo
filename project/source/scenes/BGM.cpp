#include "BGM.h"

#include "../components/OggPlayer.h"

#include "../resources/ResourceLoader.h"
#include "../resources/VorbisResource.h"

namespace cp = Components;

void BGM::Load() {
	auto oggTrack = ResourceLoader::Load<VorbisResource>("audio/music.ogg")->Load();
	auto oggPlayer = cp::OggPlayer(oggTrack);
	std::printf("Loaded BGM\n");
}