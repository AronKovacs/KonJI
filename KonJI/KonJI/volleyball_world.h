#pragma once

#include "world.h"

struct VolleyballWorld
{
	struct World super;

};

void volleyballProcessInput(struct VolleyballWorld* world, INPUT_RECORD* events, int events_len);
void volleyballUpdate(struct VolleyballWorld* world);

extern struct WorldVTable VolleyballWorldVTable;

void volleyballWorldInit(struct VolleyballWorld* world);