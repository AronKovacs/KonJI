#include "world.h"

void worldProcessInput(struct World* world, INPUT_RECORD* events, int events_len)
{
	world->vtable->worldProcessInput(world, events, events_len);
}

void worldUpdate(struct World* world)
{
	world->vtable->worldUpdate(world);
}

void worldDraw(struct World* world)
{

}