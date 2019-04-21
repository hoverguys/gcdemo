#include "VorbisResource.h"

void VorbisResource::Initialize() {
	unsigned char* data = static_cast<unsigned char*>(address);
	auto s = eastl::make_shared<VorbisTrack>();
	s->data = data;
	s->size = size;

	internal = s;
}

eastl::shared_ptr<VorbisTrack> VorbisResource::Load() {
	return internal;
}