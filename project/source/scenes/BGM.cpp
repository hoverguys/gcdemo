#include "BGM.h"

#include "../components/OggPlayer.h"

#include "../resources/ResourceLoader.h"
#include "../resources/VorbisResource.h"

namespace cp = Components;

void BGM::load() {
	auto musicPlayer = create();
	auto oggTrack = ResourceLoader::Load<VorbisResource>("audio/music.ogg")->Load();
	musicPlayer.assign<cp::OggPlayer>(oggTrack);
	std::printf("Loaded BGM\n");
}