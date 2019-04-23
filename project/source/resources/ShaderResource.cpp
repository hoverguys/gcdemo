#include "pchheader.h"
#include "ShaderResource.h"

#include "rendering/Shader.h"

void ShaderResource::Initialize() {
    auto s = eastl::make_shared<Shader>(data);
    internal = s;
}

eastl::shared_ptr<Shader> ShaderResource::Load() {
    return internal;
}
