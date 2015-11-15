#pragma once

#include "palette.h"
#include "lists.h"

#include <stdbool.h>

struct World;

void worldProcessInput(struct World* world, INPUT_RECORD* events, int events_len);
void worldUpdate(struct World* world);
void worldDraw(struct World* world);

struct WorldVTable
{
	void(*worldProcessInput)(struct World*, INPUT_RECORD* events, int events_len);
	void(*worldUpdate)(struct World*);
};

struct World
{
	struct WorldVTable *vtable;

	bool b_running;
	int players;
	COLORREF palette[16];
	struct ListNode* entities;
};