#include "volleyball_world.h"

#include <stdbool.h>

struct WorldVTable VolleyballWorldVTable =
{
	&volleyballProcessInput,
	&volleyballUpdate
};

void volleyballProcessInput(struct VolleyballWorld* world, INPUT_RECORD* events, int events_len)
{
	// Now, cycle through all the events that have happened:
	for (DWORD i = 0; i < events_len; ++i) {

		// Check the event type: was it a key?
		if (events[i].EventType == KEY_EVENT) {

			// Yes! Was the key code the escape key?
			if (events[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {

				// Yes, it was, so set the appIsRunning to false.
				world->super.b_running = false;
			}
		}
	}

}

void volleyballUpdate(struct VolleyballWorld* world)
{
	//printf("volleyball update\n");
}

void volleyballWorldInit(struct VolleyballWorld* world)
{
	world->super.vtable = &VolleyballWorldVTable;
	world->super.b_running = true;
	world->super.entities = NULL;
}