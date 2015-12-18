#pragma once

#include "entity.h"
#include "vector2d.h"
#include <math.h>
#include <stdbool.h>

int physicsCollisionBoundingBox(struct Entity *entity1, struct Entity *entity2);
struct Vector2d* physicsCollisionPixelPerfect(const struct Entity *entity1, const struct Entity *entity2, unsigned int* pixels_len);

void entityPhysicsApply(struct Entity* entity, double delta_time);