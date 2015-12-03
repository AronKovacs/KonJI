#pragma once

#include <math.h>

struct Vector2 {
	double x;
	double y;
};

struct Vector2 vector2Add(struct Vector2 vector1, struct Vector2 vector2);
struct Vector2 vector2Subtract(struct Vector2 vector1, struct Vector2 vector2);
struct Vector2 vector2ScalarMult(double scalar, struct Vector2 vector);
double vector2DotProduct(struct Vector2 vector1, struct Vector2 vector2);
double vector2Magnitude(struct Vector2 vector);
struct Vector2 vector2Normalize(struct Vector2 vector);