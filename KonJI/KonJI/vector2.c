#pragma once

#include "vector2.h"

struct Vector2 vector2Add(struct Vector2 vector1, struct Vector2 vector2) {
	struct Vector2 ret_vector = {vector1.x + vector2.x, vector1.y + vector2.y};
	return ret_vector;
}

struct Vector2 vector2Subtract(struct Vector2 vector1, struct Vector2 vector2) {
	struct Vector2 ret_vector = {vector1.x - vector2.x, vector1.y - vector2.y};
	return ret_vector;
}

struct Vector2 vector2ScalarMult(double scalar, struct Vector2 vector) {
	struct Vector2 ret_vector = {scalar * vector.x, scalar * vector.y};
	return ret_vector;
}

double vector2DotProduct(struct Vector2 vector1, struct Vector2 vector2) {
	return (vector1.x * vector2.x) + (vector1.y * vector2.y);
}

double vector2Magnitude(struct Vector2 vector) {
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

struct Vector2 vector2Normalize(struct Vector2 vector) {
	double magnitude = vector2Magnitude(vector);

	struct Vector2 ret_vector = {vector.x / magnitude, vector.y / magnitude};

	return ret_vector;
}