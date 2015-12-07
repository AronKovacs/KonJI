#pragma once

#include <math.h>

struct Vector2i {
	int x;
	int y;
};

struct Vector2i vector2iAdd(struct Vector2i vector1, struct Vector2i vector2);
struct Vector2i vector2iSubtract(struct Vector2i vector1, struct Vector2i vector2);
struct Vector2i vector2iScalarMult(double scalar, struct Vector2i vector);
double vector2iDotProduct(struct Vector2i vector1, struct Vector2i vector2);
double vector2iMagnitude(struct Vector2i vector);
struct Vector2i vector2iNormalize(struct Vector2i vector);
