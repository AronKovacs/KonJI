#pragma once

#include "physics.h"

int collisionBoundingBox(struct Entity *entity1, struct Entity *entity2) {
	return (abs(entity1->x - entity2->x) * 2 < (entity1->sprite->w + entity2->sprite->w)) &&
		   (abs(entity1->y - entity2->y) * 2 < (entity1->sprite->h + entity2->sprite->h));
}

int collisionPixelPerfect(struct Entity *entity1, struct Entity *entity2) {
	if (collisionBoundingBox(entity1, entity2)) {

	}
	return 0;
}