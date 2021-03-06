# Project setup
cmake_minimum_required(VERSION 3.1)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/devkitPPC.cmake)
set(CMAKE_CXX_STANDARD 14)
project(gcdemo C CXX ASM)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(SetupOGC)
include(Tools)
include(PrecompiledHeader)
include(GitVersion)

# Options
set(EMBED_RESOURCES true CACHE BOOL "Embed resource pack into the binary")
set(GENERATE_SD_IMAGE false CACHE BOOL "Generate SD image for Dolphin")

# Sources
file(GLOB_RECURSE SOURCE_FILES source/*)
add_multi_target(gcdemo "${SOURCE_FILES}")
add_multi_precompiled_header(gcdemo source/pchheader.h)
include_directories(source)

# Dependencies
add_default_libraries(gcdemo fat asnd ogc m)
add_port_libraries(gcdemo ogg vorbisidec EASTL)

# EASTL platform definition
add_definitions(-DEA_PLATFORM_GEKKO)

# Create resource pack
include(../Assets)
add_resource_pack(gcdemo-data ${ASSETS_PREFIX} ${ASSETS})

if(EMBED_RESOURCES)
	get_property(RESOURCEFILE TARGET gcdemo-data PROPERTY OUTPUT_NAME)
	embed_resources(gcdemo ${RESOURCEFILE})
	add_definitions(-DEMBED_RESOURCES)
else()
	add_multi_dependency(gcdemo gcdemo-data)
endif()

if (GENERATE_SD_IMAGE)
	add_sd_image(gcdemo-sd "gcdemo-data.gcr")
	add_multi_dependency(gcdemo gcdemo-sd)
endif()

# Create .dol
add_dol_targets(gcdemo)
