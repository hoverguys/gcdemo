#pragma once

#include "Resource.h"

class Shader;

/*! \brief Shader resource loader
 *  Loads a shader from a shader file in memory
 */
class ShaderResource : public Resource {
public:
    /*!
     * \brief Load a shader from a shader file
     *
     * \param base Pointer to the shader file
     * \param size Size of the shader file
     */
    ShaderResource(eastl::span<char> span) : Resource(span) {}

    /*!
     * \brief Load and get the shader
     *
     * \return Pointer to the loaded shader
     */
    eastl::shared_ptr<Shader> Load();

    long int ReferenceCount() override {
        return internal == nullptr ? 0 : internal.use_count();
    }

    void Initialize() override;

private:
    eastl::shared_ptr<Shader> internal;
};
