#pragma once

#include "vector2i.h"

struct Vector2i vector2iAdd(struct Vector2i vector1, struct Vector2i vector2) {
	struct Vector2i ret_vector = { vector1.x + vector2.x, vector1.y + vector2.y };
	return ret_vector;
}

struct Vector2i vector2iSubtract(struct Vector2i vector1, struct Vector2i vector2) {
	struct Vector2i ret_vector = { vector1.x - vector2.x, vector1.y - vector2.y };
	return ret_vector;
}

struct Vector2i vector2iScalarMult(double scalar, struct Vector2i vector) {
	struct Vector2i ret_vector = { scalar * vector.x, scalar * vector.y };
	return ret_vector;
}

double vector2iDotProduct(struct Vector2i vector1, struct Vector2i vector2) {
	return (vector1.x * vector2.x) + (vector1.y * vector2.y);
}

double vector2iMagnitude(struct Vector2i vector) {
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

struct Vector2i vector2iNormalize(struct Vector2i vector) {
	double magnitude = vector2iMagnitude(vector);

	struct Vector2i ret_vector = { vector.x / magnitude, vector.y / magnitude };

	return ret_vector;
}