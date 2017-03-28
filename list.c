#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static void copy_to_node(ITEM *pnew, ITEM *pold)
{
	memcpy(pnew, pold, sizeof(ITEM));
}

void list_init(List *plist)
{
	if (plist) {
		memset(plist, 0, sizeof(List));
	}
}

BOOL list_is_empty(const List *plist)
{
	if (plist == NULL) {
		return TRUE;
	}
	
	return plist->count ? FALSE : TRUE;
}

BOOL list_is_full(const List *plist)
{
	Node *node = NULL;

	node = (Node *)malloc(sizeof(Node));
	if (node == NULL) {
		return TRUE;	
	}
	
	free(node);

	return FALSE;
}

BOOL list_add(List *plist, Node *pnode)
{
	if (list_is_full(plist)) {
		printf("No memory available\n");
		return FALSE;
	}

	Node *node = (Node *)malloc(sizeof(Node));
	if (node == NULL) {
		printf("malloc node failed\n");
		return FALSE;
	}

	node->item = pnode->item;
	node->next = plist->node;
	plist->node = node;
	plist->count++;

	return TRUE;
}

BOOL list_delete(List *plist, Node *pnode)
{
	Node *p = NULL;
	Node *q = NULL;
	int count = 0;

	// check list empty
	if (plist == NULL || list_is_empty(plist)) {
		printf("list is empty\n");
		return FALSE;
	}	

	p = plist->node;
	count = plist->count;

	// if the first, then delete
	if (strcmp(p->item.name, pnode->item.name) == 0) {
		plist->node = p->next;
		count--;

		free(p);
		return TRUE;
	}
	
	q = p->next;
	
	while (q) {
		if (strcmp(q->item.name, pnode->item.name)) {
			p = p->next;
			q = q->next;
			continue;
		}
	
		p->next = q->next;
		count--;

		free(q);
		return TRUE;
	}
	
	printf("person %s not exist\n", pnode->item.name);
	return FALSE;
}

void list_show(const List *plist, void (*show_cb)(Node *pnode))
{
	Node *p = NULL;
	
	if (list_is_empty(plist)) {
		printf("list is empty\n");
		return;
	}

	p = plist->node;

	while (p) {
		show_cb(p);
		p = p->next;
	}
	
	return;
}

int list_count(const List *plist)
{
	return plist->count;
}
