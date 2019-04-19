#pragma once

#include "../pchheader.h"

namespace Components {
/* \brief Denotes a sprite which material is affected by alpha */
struct AlphaFade {
    enum class FadeDirection {
        FadeIn, FadeOut
    } direction;

    u64 startTime;
    u64 duration;
    bool done = true;
};
} // namespace Components