#include "lists.h"

struct EntityListNode* entityListCreate(struct Entity* entity) {
	struct EntityListNode* new_node = malloc(sizeof(struct EntityListNode));
	new_node->entity = entity;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

struct EntityListNode* entityListPop(struct EntityListNode* start, int n) {
	struct EntityListNode* node = start;
	for (int i = 0; i < n; i++) {
		node = node->next;
	}
	if (node->prev == NULL) {
		entityListFree(node);
		node->next->prev = NULL;
		return node->next;
	}
	if (node->next == NULL) {
		node->prev->next = NULL;
		entityListFree(node);
		return start;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	entityListFree(node);
	return start;
}

struct EntityListNode* entityListInsert(struct EntityListNode* start, struct Entity* entity, int n) {
	struct EntityListNode* node = start;
	struct EntityListNode* ins_node = malloc(sizeof(struct EntityListNode));
	ins_node->entity = entity;

	if (n == 0) {
		node->prev = ins_node;
		ins_node->prev = NULL;
		ins_node->next = node;
		return ins_node;
	}

	// n-1        n  
	//ins_node - node
	for (int i = 0; i < n; i++) {
		node = node->next;
	}

	ins_node->prev = node->prev;
	ins_node->next = node;
	node->prev->next = ins_node;
	node->prev = ins_node;

	return start;
}

struct EntityListNode* entityListPush(struct EntityListNode* start, struct Entity* entity) {
	struct EntityListNode* node = start;
	struct EntityListNode* push_node = malloc(sizeof(struct EntityListNode));
	push_node->entity = entity;
	push_node->next = NULL;
	while (1) {
		if (node->next == NULL) {
			node->next = push_node;
			push_node->prev = node;
			break;
		}
		node = node->next;
	}
	return start;
}

void entityListSwap(struct EntityListNode* start, int n1, int n2) {
	if (n1 == n2)
		return;

	struct EntityListNode* node = start;
	struct EntityListNode* swap_node1 = NULL;
	struct EntityListNode* swap_node2 = NULL;
	
	for (int i = 0; i < max(n1, n2)+1; i++) {
		if (n1 == i) {
			swap_node1 = node;
		}
		if (n2 == i) {
			swap_node2 = node;
		}
		if (n1 != NULL && n2 != NULL) {
			break;
		}
		node = node->next;
	}

	struct Entity *temp = swap_node1->entity;
	swap_node1->entity  = swap_node2->entity;
	swap_node2->entity  = temp;
}

void entityListFree(struct EntityListNode* node) {
	entityFree(node->entity);
	free(node);
}

struct EntityListNode* entityListSort(struct EntityListNode* start);