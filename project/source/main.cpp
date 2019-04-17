#include "pchheader.h"
#include <fat.h>
#include <ogc/lwp_watchdog.h>

#include "rendering/Graphics.h"
#include "resources/MeshResource.h"
#include "resources/ResourceLoader.h"
#include "resources/TextureResource.h"

#include "Demo.h"

int main() {
	// DEBUG: Enable USBGecko
	CON_EnableGecko(1, 0);

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
