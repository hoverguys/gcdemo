#pragma once

/*!
 * \brief Resource loader
 * Loads a resource from memory
 */
class Resource {
public:
    ~Resource() {
        free(data.data());
    }

    virtual void Initialize() = 0;
    virtual long int ReferenceCount() = 0;

protected:
    friend class ResourceLoader;

    /*!
     * \brief Loads a resource from a memory pointer and size
     *
     * \param address Pointer to resource data
     * \param size Size of resource data
     */
    Resource(eastl::span<char> span) : data(span) {}

    eastl::span<char> data;
};
