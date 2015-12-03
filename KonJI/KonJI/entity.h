#pragma once

#include "sprite.h"
#include <math.h>

//needs more meetings
struct Entity {
	double x;
	double y;
	int z;

	//AnimatedSprite
	int tpf; //time per frame[ms]
	unsigned char frame;

	struct Sprite* sprite;
};

struct Entity* entityCreate(struct Sprite* sprite, double x, double y, int z, int tpf);
void entityDraw(struct Window* window, struct Entity* entity);
void entityFree(struct Entity* entity);