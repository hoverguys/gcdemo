#include "Script.h"

#include "components/Sprite.h"

namespace cp = Components;

void Script::at(u64 at, std::shared_ptr<ScriptEvent> event) {
	events.push(ScriptEventEntry(at, event));
}
