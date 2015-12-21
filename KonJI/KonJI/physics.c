#pragma once

#include <stdbool.h>
#include "physics.h"
#include "vector2i.h"

bool eq_charinfo(CHAR_INFO ch1, CHAR_INFO ch2) {
	if (ch1.Attributes == ch1.Attributes && ch1.Char.AsciiChar == ch2.Char.AsciiChar) {
		return true;
	}
	return false;
}

int collisionBoundingBox(struct Entity *entity1, struct Entity *entity2) {
	int e1x = (int)(entity1->position.x + (entity1->sprite->w / 2));
	int e1y = (int)(entity1->position.y + (entity1->sprite->h / 2));
	int e2x = (int)(entity2->position.x + (entity2->sprite->w / 2));
	int e2y = (int)(entity2->position.y + (entity2->sprite->h / 2));

	return (abs(e1x- e2x) * 2 < (entity1->sprite->w + entity2->sprite->w)) 
		   &&
		   (abs(e1y - e2y) * 2 < (entity1->sprite->h + entity2->sprite->h));
}

struct Vector2d* collisionPixelPerfect(const struct Entity *entity1, const struct Entity *entity2, unsigned int* pixels_len) {
	if (!collisionBoundingBox(entity1, entity2)) {
		return 0;
	}

	struct Vector2i topLeft, bottomRight;
	if (entity1->position.y > entity2->position.y) {
		topLeft.y = (int)floor(entity1->position.y);
	}
	else {
		topLeft.y = (int)floor(entity2->position.y);
	}

	if ((entity1->position.y + entity1->sprite->h) < (entity2->position.y + entity2->sprite->h)) {
		bottomRight.y = (int)floor(entity1->position.y + entity1->sprite->h);
	}
	else {
		bottomRight.y = (int)floor(entity2->position.y + entity2->sprite->h);
	}

	if (entity1->position.x > entity2->position.x) {
		topLeft.x = (int)floor(entity1->position.x);
	}
	else {
		topLeft.x = (int)floor(entity2->position.x);
	}

	if (entity1->position.x + entity1->sprite->w < entity2->position.x + entity2->sprite->w) {
		bottomRight.x = (int)floor(entity1->position.x + entity1->sprite->w);
	}
	else {
		bottomRight.x = (int)floor(entity2->position.x + entity2->sprite->w);
	}

	*pixels_len = 0;
	struct Vector2d* pixels = NULL;

	CHAR_INFO empty_pixel;
	empty_pixel.Attributes = 0;
	empty_pixel.Char.AsciiChar = 0;
	for (int y = topLeft.y; y < bottomRight.y; y++) {
		for (int x = topLeft.x; x < bottomRight.x; x++) {
			CHAR_INFO pixel1 = spriteAt(entity1->sprite, x - (int)floor(entity1->position.x), y - (int)floor(entity1->position.y));
			CHAR_INFO pixel2 = spriteAt(entity2->sprite, x - (int)floor(entity2->position.x), y - (int)floor(entity2->position.y));

			if (!eq_charinfo(pixel1, empty_pixel) && !eq_charinfo(pixel2, empty_pixel)) {
				(*pixels_len)++;
				pixels = (struct Vector2d*)realloc(pixels, sizeof(struct Vector2d) * (*pixels_len));
				pixels[(*pixels_len) - 1].x = x;
				pixels[(*pixels_len) - 1].y = y;
			}
		}
	}

	return pixels;
}

void entityPhysicsApply(struct Entity* entity, double delta_time) {
	entity->ephysics.acceleration = vector2dAdd(entity->ephysics.acceleration, vector2dScalarMult(delta_time, entity->ephysics.jerk));
	entity->ephysics.speed = vector2dAdd(entity->ephysics.speed, vector2dScalarMult(delta_time, entity->ephysics.acceleration));

	entity->ephysics.prev_position = entity->position;
	entity->position = vector2dAdd(entity->position, vector2dScalarMult(delta_time, entity->ephysics.speed));
}