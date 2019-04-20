#include "VorbisResource.h"

void VorbisResource::Initialize() {
	unsigned char* data = static_cast<unsigned char*>(address);
	auto s = std::make_shared<VorbisTrack>();
	s->data = data;
	s->size = size;

	internal = s;
}

std::shared_ptr<VorbisTrack> VorbisResource::Load() {
	return internal;
}