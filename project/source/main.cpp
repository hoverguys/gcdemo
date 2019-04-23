#include "pchheader.h"
#include "rendering/Graphics.h"
#include "resources/ResourceLoader.h"

#include "Demo.h"
#include <malloc.h>

void* operator new[](size_t size, const char* /*name*/, int /*flags*/, unsigned /*debugFlags*/, const char* /*file*/,
                     int /*line*/) {
    return malloc(size);
}

void* operator new[](size_t size, size_t alignment, size_t /*alignmentOffset*/, const char* /*name*/, int flags,
                     unsigned /*debugFlags*/, const char* /*file*/, int /*line*/) {
    // Substitute your aligned malloc.
    return memalign(size, alignment);
}

int main() {
    // DEBUG: Enable USBGecko
    CON_EnableGecko(1, 0);

    ASND_Init();

    // Initialize graphics
    Graphics::Init();

    // Setup storage
    fatInitDefault();
#ifdef WII
    fatMountSimple("sd", &__io_wiisd);
#else
    fatMountSimple("sd", &__io_gcsdb);
#endif

    // Load assets
    ResourceLoader::LoadPack("sd:/rehover-data.gcr");

    // Start game
    Demo demo;
    demo.init();

    while (!SYS_ResetButtonDown()) {
        // Logic
        demo.update(1.f / Graphics::GetFramerate());

        // Render to XFB
        Graphics::Done();

        Graphics::Wait();
    }

    return 0;
}
