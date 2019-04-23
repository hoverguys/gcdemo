#pragma once

#include "Resource.h"

class Mesh;

/*! \brief BMB file header
 */
struct MeshResourceHeader {
    unsigned short vcount;  /*< Vertex count        */
    unsigned short ncount;  /*< Normal count        */
    unsigned short vtcount; /*< UV Coordinate count */
    unsigned short fcount;  /*< Face/Index count    */
};

/*!
 * \brief Mesh resource loader
 * Loads a mesh from a BMB file in memory
 */
class MeshResource : public Resource {
public:
    /*!
     * \brief Loads a mesh from a BMB file in memory
     *
     * \param base Pointer to BMB file data
     * \param size Size of the BMB file
     */
    MeshResource(eastl::span<char> span) : Resource(span) {}

    /*!
     * \brief Load and get the mesh
     *
     * \return Pointer to the loaded mesh
     */
    eastl::shared_ptr<Mesh> Load();

    long int ReferenceCount() override {
        return internal == nullptr ? 0 : internal.use_count();
    }

    void Initialize() override;

private:
    MeshResourceHeader* header = nullptr;
    bool loaded = false;
    eastl::shared_ptr<Mesh> internal;
};
