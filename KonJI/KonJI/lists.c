#include <stdlib.h>
#include "lists.h"
#include "entity.h"

struct ListNode* pop_ListNode_Entity(struct ListNode* node, int n) {
	for (int i = 0; i < n; i++) {
		node = node->next;
	}
	if (node->prev == NULL) {
		free_ListNode(node);
	}
}
void push_ListNode_Entity(struct ListNode* node, struct Entity* entity, int n);
void qsort_LinkedListNode_Entity();
