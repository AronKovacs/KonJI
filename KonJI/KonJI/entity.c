#include "entity.h"

void free_Entity(struct Entity* entity) {
	free(entity->sprite->bitmap);
}