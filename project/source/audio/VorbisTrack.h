#pragma once

class VorbisTrack {
protected:
	friend class VorbisResource;

public:
	unsigned char* data;
	unsigned int size;
};