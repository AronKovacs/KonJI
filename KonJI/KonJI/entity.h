#pragma once

#include "sprite.h"
#include "vector2d.h"
#include <math.h>

struct EntityPhysics {
	bool b_static;
	bool b_collides;
	bool b_affected_by_collisions;

	double bounciness;

	struct Vector2d prev_position;

	struct Vector2d speed;
	struct Vector2d acceleration;
	struct Vector2d jerk;

	struct Vector2d center;
	double radius;

};


//needs more meetings
struct Entity {
	struct Vector2d position;
	int z;

	struct EntityPhysics ephysics;

	//AnimatedSprite
	int tpf; //time per frame[ms]
	unsigned char frame;

	struct Sprite* sprite;
};

struct Entity* entityCreate(struct Sprite* sprite, double x, double y, int z, int tpf);
void entityDraw(struct Window* window, struct Entity* entity);
void entityFree(struct Entity* entity);