#pragma once

#include <stdbool.h>
#include "physics.h"
#include "vector2i.h"

bool eq_charinfo(CHAR_INFO ch1, CHAR_INFO ch2) {
	if (ch1.Attributes == ch1.Attributes && ch1.Char.AsciiChar == ch2.Char.AsciiChar) {
		return true;
	}
	else {
		return false;
	}
}

int collisionBoundingBox(struct Entity *entity1, struct Entity *entity2) {
	return (abs(entity1->x - entity2->x) * 2 < (entity1->sprite->w + entity2->sprite->w)) &&
		   (abs(entity1->y - entity2->y) * 2 < (entity1->sprite->h + entity2->sprite->h));
}

int collisionPixelPerfect(struct Entity *entity1, struct Entity *entity2) {
	if (!collisionBoundingBox(entity1, entity2)) {
		return 0;
	}

	struct Vector2i topLeft, bottomRight;
	if (entity1->y > entity2->y) {
		topLeft.y = (int)floor(entity1->y);
	}
	else {
		topLeft.y = (int)floor(entity2->y);
	}

	if ( (entity1->y + entity1->sprite->h) < (entity2->y + entity2->sprite->h)) {
		bottomRight.y = (int)floor(entity1->y + entity1->sprite->h);
	}
	else {
		bottomRight.y = (int)floor(entity2->y + entity2->sprite->h);
	}

	if (entity1->x > entity2->x) {
		topLeft.x = (int)floor(entity1->x);
	}
	else {
		topLeft.x = (int)floor(entity2->x);
	}

	if (entity1->x + entity1->sprite->w < entity2->x + entity2->sprite->w) {
		bottomRight.x = (int)floor(entity1->x + entity1->sprite->w);
	}
	else {
		bottomRight.x = (int)floor(entity2->x + entity2->sprite->w);
	}

	CHAR_INFO empty_pixel;
	empty_pixel.Attributes = 0;
	empty_pixel.Char.AsciiChar = 0;
	for (int x = topLeft.x; x < bottomRight.x; x++) {
		for (int y = topLeft.y; y < bottomRight.y; y++) {
			CHAR_INFO pixel1 = spriteAt(entity1->sprite, entity1->frame, x - (int)floor(entity1->x), y - (int)floor(entity1->y));
			CHAR_INFO pixel2 = spriteAt(entity2->sprite, entity2->frame, x - (int)floor(entity2->x), y - (int)floor(entity2->y));

			if (!eq_charinfo(pixel1, empty_pixel) && !eq_charinfo(pixel2, empty_pixel)) {
				return true;
			}
		}
	}

	return 0;
}