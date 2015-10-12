#include "lists.h"

struct ListNode* create_ListNode_Entity(struct Entity* entity) {
	struct ListNode* new_node = malloc(sizeof(struct ListNode));
	new_node->entity = entity;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

struct ListNode* pop_ListNode_Entity(struct ListNode* start, int n) {
	struct ListNode* node = start;
	for (int i = 0; i < n; i++) {
		node = node->next;
	}
	if (node->prev == NULL) {
		free_ListNode(node);
		node->next->prev = NULL;
		return node->next;
	}
	if (node->next == NULL) {
		node->prev->next = NULL;
		free_ListNode(node);
		return start;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free_ListNode(node);
	return start;
}

struct ListNode* insert_ListNode_Entity(struct ListNode* start, struct Entity* entity, int n) {
	struct ListNode* node = start;
	struct ListNode* ins_node = malloc(sizeof(struct ListNode));
	ins_node->entity = entity;
	if (n == 0) {
		ins_node->next = node;
		node->prev = ins_node;
		ins_node->prev = NULL;
		return ins_node;
	}
	
	for (int i = 0; i < n; i++) {
		if (node->next == NULL) {
			node->next = ins_node;
			ins_node->prev = node;
			ins_node->next = NULL;
			return start;
		}
		node = node->next;
	}
	node->prev->next = ins_node;
	node->prev = ins_node;
	//printf("00%d", node->prev->prev->next->entity->x);
	return start;
}

struct ListNode* push_ListNode_Entity(struct ListNode* start, struct Entity* entity) {
	struct ListNode* node = start;
	struct ListNode* push_node = malloc(sizeof(struct ListNode));
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

int swap_ListNode_Entity(struct ListNode* start, int n1, int n2) {
	if (n1 == n2)
		return start;
	struct ListNode* node = start;
	struct ListNode* swap_node1;
	struct ListNode* swap_node2;
	for (int i = 0; i < max(n1, n2); i++) {
		if (node->next == NULL)
			return start;
		if (i = n1)
			swap_node1 = node;
		if (i = n2)
			swap_node2 = node;
		node = node->next;
	}

	struct ListNode* temp = swap_node1;

	swap_node1->prev->next = swap_node2;
	swap_node1->next->prev = swap_node2;
	swap_node1->next = swap_node2->next;
	swap_node1->prev = swap_node2->prev;

	swap_node2->prev->next = temp;
	swap_node2->next->prev = temp;
	swap_node2->next = temp->next;
	swap_node2->prev = temp->prev;

	return start;
}

void free_ListNode(struct ListNode* node) {
	//free_Entity(node->entity); fix this pico
}

struct ListNode* qsort_LinkedListNode_Entity(struct ListNode* start);