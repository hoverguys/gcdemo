#pragma once

#include "Resource.h"

class ResourceLoader {
public:
    typedef unsigned int FileHash;

    static void LoadPack(const char* path);

    template <typename T>
    static eastl::shared_ptr<T> Load(FileHash hash) {
        auto entry = cache.find(hash);
        if (entry != cache.end()) {
            return eastl::static_pointer_cast<T>(entry->second);
        }

        auto file = files.find(hash);
        if (file == files.end()) {
            std::printf("File %08x not found\n", hash);
            return nullptr;
        }
        auto info = file->second;

#ifndef EMBED_RESOURCES
        // Allocate buffer for resource
        auto offset = info.first;
        auto size = info.second;
        unsigned char* address = (unsigned char*)memalign(32, size);
        memoryAllocated += size;

        // Load from pack
        std::FILE* fp = std::fopen(packfile, "rb");
        assert(fp);

        // Seek to offset and copy over data
        std::fseek(fp, offset, SEEK_SET);
        std::fread(address, size, 1, fp);
        std::fclose(fp);

        std::printf("Loading file %08x from file, allocated %d\n", hash, size);
#else
        unsigned char* address = (unsigned char*)embedded;
        address += info.first; // Add offset
        std::printf("Loading file %08x from memory at address: %p\n", hash, address);
#endif

        auto resource = eastl::make_shared<T>(eastl::span<char>((char*)address, info.second));
        resource->Initialize();

        // Cache loaded resource
        cache.emplace(hash, resource);

        return resource;
    }

    template <typename T>
    static inline eastl::shared_ptr<T> Load(const char* path) {
        static_assert(eastl::is_base_of<Resource, T>::value, "Must inherit of type Resource");
        return Load<T>(fnv1_hash(path));
    }

    static void UnloadUnused() {
#ifndef EMBED_RESOURCES
        auto removed = 0;
        auto freed = 0;
        for (auto it = cache.cbegin(); it != cache.cend();) {
            if (it->second.use_count() <= 1 && it->second->ReferenceCount() <= 1) {
                // Removing it from the cache should get rid of the last reference
                // and cause the destructor to be called.
                std::printf("Unloading resource %08x\n", it->first);
                freed += it->second->data.size_bytes();
                it = cache.erase(it);
                removed++;
            } else {
                ++it;
            }
        }

        memoryAllocated -= freed;
        std::printf("Unloaded %d resources, freed %d bytes (using %d bytes)\n", removed, freed, memoryAllocated);
#else
        std::printf("Asset unloading not supported in embedded mode\n");
#endif
    }

    static void PrintUsage() {
        std::printf("Resources (%d) are using %d bytes\n", cache.size(), memoryAllocated);
    }

private:
    static constexpr unsigned int fnv1_hash(const char* buffer) {
        const unsigned int fnv_prime32 = 16777619;
        unsigned int result = 2166136261;
        int i = 0;
        while (buffer[i] != '\0') {
            result *= fnv_prime32;
            result ^= (unsigned int)buffer[i++];
        }
        return result;
    }

    typedef eastl::map<FileHash, eastl::pair<unsigned int, unsigned int>> FileMap;
    static FileMap files;

    typedef eastl::map<FileHash, eastl::shared_ptr<Resource>> ResourceMap;
    static ResourceMap cache;

    static unsigned int memoryAllocated;

#ifdef EMBED_RESOURCES
    static const unsigned char* embedded;
#else
    static const char* packfile;
#endif
};
