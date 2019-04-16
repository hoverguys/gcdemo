#pragma once
#include "../pchheader.h"

namespace ex = entityx;

namespace Behaviours {

/*! \brief Hovercraft behavior
 *  Allows the hovercraft entity to be controlled by players
 */
struct Hovercraft {
	/*! Camera following the hovercraft */
	ex::Entity camera;

	/*! Update method */
	void Tick(ex::Entity entity, ex::TimeDelta dt);
};
} // namespace Behaviours
