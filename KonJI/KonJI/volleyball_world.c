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

void volleyballUpdate(struct VolleyballWorld* world, double delta_time)
{

}

void volleyballWorldInit(struct VolleyballWorld* world)
{
	world->super.vtable = &VolleyballWorldVTable;
	world->super.b_running = true;
	world->super.entities = NULL;

	struct Entity* h1 = entityCreate(spriteLoad("data/hitler_ultrawhite.kgf"), 10, 10, 0, 0);
	struct Entity* h2 = entityCreate(spriteLoad("data/hitler_ultrawhite.kgf"), 10, 10, 2, 0);
	struct Entity* h3 = entityCreate(spriteLoad("data/hitler.kgf"), 25, 25, 1, 0);
	
	world->super.entities = entityListCreate(h1);
	entityListPush(world->super.entities, h2);
	entityListPush(world->super.entities, h3);
}