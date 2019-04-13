#pragma once

#ifdef EMBED_RESOURCES
#include <gcdemo_data_gcr.h>
const unsigned char* ResourceLoader::embedded = gcdemo_data_gcr_txt;
#endif