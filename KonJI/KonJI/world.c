#include "world.h"
#include "sprite.h"

void worldProcessInput(struct World* world, INPUT_RECORD* events, int events_len)
{
	world->vtable->worldProcessInput(world, events, events_len);
}

void worldUpdate(struct World* world, double delta_time)
{
	world->vtable->worldUpdate(world);
}

void worldDraw(struct Window* window, struct World* world)
{
	if (world->entities == NULL) {
		return;
	}

	struct EntityListNode *node = world->entities;
	int n;
	for (n = 0; node->next != NULL; node = node->next, n++);

	struct Entity** entities = malloc(n * sizeof(struct Entity*));
	node = world->entities;
	for (int i = 0; node->next != NULL; node = node->next, i++){
		entities[i] = node->entity;
	}

	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && entities[j - 1]->z < entities[j]->z) {
			struct Entity* temp = entities[j - 1];
			entities[j - 1] = entities[j];
			entities[j] = temp;
			j--;
		}
	}

	for (int i = 0; i < n; i++) {
		entityDraw(window, entities[i]);
	}

	free(entities);
}