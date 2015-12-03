#pragma once

#include "entity.h"
#include "vector2.h"
#include <math.h>


int collisionBoundingBox(struct Entity *entity1, struct Entity *entity2);
int collisionPixelPerfect(struct Entity *entity1, struct Entity *entity2);