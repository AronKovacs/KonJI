#include "lists.h"

struct ListNode* createListNode_Entity(struct Entity* entity) {
	struct ListNode* new_node = malloc(sizeof(struct ListNode));
	new_node->entity = entity;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

struct ListNode* popListNode_Entity(struct ListNode* start, int n) {
	struct ListNode* node = start;
	for (int i = 0; i < n; i++) {
		node = node->next;
	}
	if (node->prev == NULL) {
		freeListNode_Entity(node);
		node->next->prev = NULL;
		return node->next;
	}
	if (node->next == NULL) {
		node->prev->next = NULL;
		freeListNode_Entity(node);
		return start;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	freeListNode_Entity(node);
	return start;
}

struct ListNode* insertListNode_Entity(struct ListNode* start, struct Entity* entity, int n) {
	struct ListNode* node = start;
	struct ListNode* ins_node = malloc(sizeof(struct ListNode));
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

struct ListNode* pushListNode_Entity(struct ListNode* start, struct Entity* entity) {
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

void swapListNode_Entity(struct ListNode* start, int n1, int n2) {
	if (n1 == n2)
		return;

	struct ListNode* node = start;
	struct ListNode* swap_node1;
	struct ListNode* swap_node2;
	
	for (int i = 0; i < max(n1, n2)+1; i++) {
		if (n1 == i) {
			swap_node1 = node;
		}
		if (n2 == i) {
			swap_node2 = node;
		}
		node = node->next;
	}

	struct Entity *temp = swap_node1->entity;
	swap_node1->entity  = swap_node2->entity;
	swap_node2->entity  = temp;
}

void freeListNode_Entity(struct ListNode* node) {
	//free_Entity(node->entity);// fix this pico
}

struct ListNode* qsortLinkedListNode_Entity(struct ListNode* start);