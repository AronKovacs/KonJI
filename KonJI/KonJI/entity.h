#pragma once
#include "sprite.h"

//needs more meetings
struct Entity {
	int x;
	int y;
	int z;

	//AnimatedSprite
	int tpf; //time per frame[ms]
	unsigned char frame;

	struct Sprite* sprite;
};

void free_Entity(struct Entity*);