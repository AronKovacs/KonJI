#pragma once
#include <stdlib.h>
#include "entity.h"

struct ListNode {
	struct ListNode* prev;
	struct ListNode* next;
	struct Entity* entity;
};

struct ListNode* create_ListNode_Entity(struct Entity* entity);
struct ListNode* pop_ListNode_Entity(struct ListNode* start, int n);
struct ListNode* insert_ListNode_Entity(struct ListNode* start, struct Entity* entity, int n);
struct ListNode* push_ListNode_Entity(struct ListNode* start, struct Entity* entity);
void free_ListNode(struct ListNode* node);
int swap_ListNode_Entity(struct ListNode* start, int n1, int n2);
struct ListNode* qsort_LinkedListNode_Entity(struct ListNode* start);