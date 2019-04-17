#include "Script.h"

void Script::at(u64 time, ScriptEvent event) {
	events.push(ScriptEventEntry(time, event));
}
