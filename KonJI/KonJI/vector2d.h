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
struct Vector2d vector2dNormal(struct Vector2d vector);
double vector2dAngleLine(struct Vector2d v1, struct Vector2d v2);
struct Vector2d Vector2dRotation(struct Vector2d v, double angle);

struct Vector2d vector2dTrendLine(struct Vector2d* points, unsigned int points_len);
struct Vector2d vector2dSymmetry(struct Vector2d reflector, struct Vector2d reflected);
struct Vector2d vector2dReflection(struct Vector2d reflector, struct Vector2d reflected);
struct Vector2d vector2dCenterOfMass(struct Vector2d* points, unsigned int points_len);