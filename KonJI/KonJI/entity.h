#pragma once

//needs more meetings
struct Entity {
	int x;
	int y;
	int z;

	//AnimatedSprite
	int tpf; //time per frame[ms]
	unsigned char frame;
	//sharing
	union {
		struct Sprite* sprite;
		struct AnimatedSprite* anim_sprite;
	};
};