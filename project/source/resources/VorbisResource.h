#pragma once

#include "Resource.h"

class VorbisTrack;

/*! \brief OGG Vorbis resource loader
 *  Loads a vorbis music track from a ogg file in memory
 */
class VorbisResource : public Resource {
public:
    /*!
     * \brief Load a Vorbis track from a ogg file
     *
     * \param base Pointer to the Vorbis file
     * \param size Size of the Vorbis file
     */
    VorbisResource(eastl::span<char> span) : Resource(span) {}

    /*!
     * \brief Load and get the Vorbis track
     *
     * \return Pointer to the loaded Vorbis track
     */
    eastl::shared_ptr<VorbisTrack> Load();

    long int ReferenceCount() override {
        return internal == nullptr ? 0 : internal.use_count();
    }

    void Initialize() override;

private:
    eastl::shared_ptr<VorbisTrack> internal;
};
