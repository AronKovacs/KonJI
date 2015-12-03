#include "entity.h"

struct Entity* entityCreate(struct Sprite* sprite, double x, double y, int z, int tpf) {
	struct Entity* entity = malloc(sizeof(entity));
	entity->frame = 0;
	entity->sprite = sprite;
	entity->x = x;
	entity->y = y;
	entity->z = z;
	entity->tpf = tpf;
	return entity;
}

void entityDraw(struct Window* window, struct Entity* entity) {
	if (entity->sprite != NULL)
		spriteDraw(window, entity->sprite, floor(entity->x), floor(entity->y));
}

void entityFree(struct Entity* entity) {
	spriteFree(entity->sprite);
	free(entity);
}