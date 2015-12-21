#pragma once

#include <stdlib.h>
#include "entity.h"

struct EntityListNode {
	struct EntityListNode* prev;
	struct EntityListNode* next;
	struct Entity* entity;
};

struct EntityListNode* entityListCreate(struct Entity* entity);
struct EntityListNode* entityListPop(struct EntityListNode* start, int n);
struct EntityListNode* entityListInsert(struct EntityListNode* start, struct Entity* entity, int n);
struct EntityListNode* entityListPush(struct EntityListNode* start, struct Entity* entity);
void entityListFree(struct EntityListNode* node);
void entityListSwap(struct EntityListNode* start, int n1, int n2);