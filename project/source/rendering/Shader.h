#pragma once

class Shader {
public:
    Shader(eastl::span<char> span) : data(span) {}

    /*! \brief Calls the display list to set the TEV up accordingly
     */
    void Use();

    /*! \brief Reset to a default shader
     */
    static void Default();

    /*! \brief Reset to a default unlit shader
     */
    static void DefaultUnlit();

protected:
    friend class ShaderResource;

    eastl::span<char> data;
};
