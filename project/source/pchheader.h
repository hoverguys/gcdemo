// Cstdlib
#include <cmath>
#include <cstdio>
#include <cstring>
#include <malloc.h>

// STL
#include <EASTL/map.h>
#include <EASTL/shared_ptr.h>
#include <EASTL/array.h>
#include <EASTL/utility.h>
#include <EASTL/span.h>

// Libogc
#include <asndlib.h>
#include <fat.h>
#include <gccore.h>
#include <gctypes.h>
#include <ogc/gu.h>
#include <ogc/gx.h>

// Resource loading
#ifdef WII
#include <sdcard/wiisd_io.h>
#else
#include <sdcard/gcsd.h>
#endif

namespace Components {}

namespace cp = Components;
