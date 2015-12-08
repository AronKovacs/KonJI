#pragma once

#include <math.h>

struct Vector2d {
	double x;
	double y;
};

struct Vector2d vector2Add(struct Vector2d vector1, struct Vector2d vector2);
struct Vector2d vector2Subtract(struct Vector2d vector1, struct Vector2d vector2);
struct Vector2d vector2ScalarMult(double scalar, struct Vector2d vector);
double vector2dDotProduct(struct Vector2d vector1, struct Vector2d vector2);
double vector2dMagnitude(struct Vector2d vector);
struct Vector2d vector2dNormalize(struct Vector2d vector);