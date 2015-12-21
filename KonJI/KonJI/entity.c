#include "entity.h"
#include "vector2i.h"

struct Entity* entityCreate(struct Sprite* sprite, double x, double y, int z, int tpf) {
	struct Entity* entity = malloc(sizeof(struct Entity));
	entity->frame = 0;
	entity->sprite = sprite;
	entity->position.x = x;
	entity->position.y = y;
	entity->z = z;
	entity->tpf = tpf;
	return entity;
}

void entityDraw(struct Window* window, struct Entity* entity) {
	struct Vector2i viewport = window->worlds[window->activeWorld]->camera.pos;
	if (entity->sprite != NULL)
		spriteDraw(window, entity->sprite, floor(entity->position.x) - viewport.x, floor(entity->position.y) - viewport.y);
}

void entityFree(struct Entity* entity) {
	spriteFree(entity->sprite);
	free(entity);
}