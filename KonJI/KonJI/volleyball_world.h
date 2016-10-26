#pragma once

#include "world.h"
#include "physics.h"
#include "vector2d.h"
#include "sprite.h"

struct WorldPhysics {
	struct Vector2d gravity;
};

struct VolleyballWorld
{
	struct World super;

	struct Entity* player1;
	struct Entity* player2;

	struct Entity* ball;

	int score_max;
	int score_player1;
	struct Entity** score_pixels;
	int score_offset_x;
	int score_offset_y;
	int score_gap;
	int winner;

	struct WorldPhysics wphysics;
};

void volleyballProcessInput(struct VolleyballWorld* world, INPUT_RECORD* events, int events_len);
void volleyballUpdate(struct VolleyballWorld* world, double delta_time);

extern struct WorldVTable VolleyballWorldVTable;

void volleyballWorldInit(struct VolleyballWorld* world);