#pragma once

#include "vector2d.h"

struct Vector2d vector2Add(struct Vector2d vector1, struct Vector2d vector2) {
	struct Vector2d ret_vector = {vector1.x + vector2.x, vector1.y + vector2.y};
	return ret_vector;
}

struct Vector2d vector2Subtract(struct Vector2d vector1, struct Vector2d vector2) {
	struct Vector2d ret_vector = {vector1.x - vector2.x, vector1.y - vector2.y};
	return ret_vector;
}

struct Vector2d vector2ScalarMult(double scalar, struct Vector2d vector) {
	struct Vector2d ret_vector = {scalar * vector.x, scalar * vector.y};
	return ret_vector;
}

double vector2dDotProduct(struct Vector2d vector1, struct Vector2d vector2) {
	return (vector1.x * vector2.x) + (vector1.y * vector2.y);
}

double vector2dMagnitude(struct Vector2d vector) {
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

struct Vector2d vector2dNormalize(struct Vector2d vector) {
	double magnitude = vector2dMagnitude(vector);

	struct Vector2d ret_vector = {vector.x / magnitude, vector.y / magnitude};

	return ret_vector;
}