#pragma once

#include "entity.h"
#include "vector2d.h"
#include <math.h>
#include <stdbool.h>

void entityPhysicsApply(struct Entity* entity, double delta_time);

int collisionBoundingBox(struct Entity *entity1, struct Entity *entity2);
struct Vector2d* collisionPixelPerfect(const struct Entity *entity1, const struct Entity *entity2, unsigned int* pixels_len);
