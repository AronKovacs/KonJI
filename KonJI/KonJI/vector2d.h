#pragma once

#include <math.h>
#include <stdbool.h>

struct Vector2d {
	double x;
	double y;
};

struct Vector2d vector2dAdd(struct Vector2d vector1, struct Vector2d vector2);
struct Vector2d vector2dSubtract(struct Vector2d vector1, struct Vector2d vector2);
struct Vector2d vector2dScalarMult(double scalar, struct Vector2d vector);
double vector2dDotProduct(struct Vector2d vector1, struct Vector2d vector2);
double vector2dMagnitude(struct Vector2d vector);
struct Vector2d vector2dNormalize(struct Vector2d vector);
struct Vector2d vector2dNormal(struct Vector2d vector);
double vector2dAngleLine(struct Vector2d v1, struct Vector2d v2);
struct Vector2d vector2dRotation(struct Vector2d v, double angle);
double vector2dPointPointDistance(struct Vector2d point1, struct Vector2d point2);

struct Vector2d vector2dTrendLine(struct Vector2d* points, unsigned int points_len);
struct Vector2d vector2dSymmetry(struct Vector2d reflector, struct Vector2d reflected);
struct Vector2d vector2dReflection(struct Vector2d reflector, struct Vector2d reflected);

struct Vector2d vector2dLineLineIntersection(struct Vector2d start1, struct Vector2d vect1, struct Vector2d start2, struct Vector2d vect2, bool* parallel);

struct Vector2d vector2dCenterOfMass(struct Vector2d* points, unsigned int points_len);