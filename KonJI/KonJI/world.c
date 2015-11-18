#include "world.h"
#include "sprite.h"

void worldProcessInput(struct World* world, INPUT_RECORD* events, int events_len)
{
	world->vtable->worldProcessInput(world, events, events_len);
}

void worldUpdate(struct World* world, double delta_time)
{
	world->vtable->worldUpdate(world);
}

void worldDraw(struct Window* window, struct World* world)
{

}