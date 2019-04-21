#include "ShaderResource.h"

void ShaderResource::Initialize() {
	unsigned char* data = static_cast<unsigned char*>(address);
	auto s = eastl::make_shared<Shader>();
	s->data = data;
	s->size = size;

	internal = s;
}

eastl::shared_ptr<Shader> ShaderResource::Load() { return internal; }