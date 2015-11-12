#pragma once
#include <stdlib.h>
#include "entity.h"

struct ListNode {
	struct ListNode* prev;
	struct ListNode* next;
	struct Entity* entity;
};

struct ListNode* createListNode_Entity(struct Entity* entity);
struct ListNode* popListNode_Entity(struct ListNode* start, int n);
struct ListNode* insertListNode_Entity(struct ListNode* start, struct Entity* entity, int n);
struct ListNode* pushListNode_Entity(struct ListNode* start, struct Entity* entity);
void freeListNode_Entity(struct ListNode* node);
//struct ListNode* swapListNode_Entity(struct ListNode* start, int n1, int n2);
struct ListNode* qsortLinkedListNode_Entity(struct ListNode* start);