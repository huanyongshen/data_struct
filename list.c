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

BOOL list_is_empty(List *plist)
{
	if (plist == NULL) {
		return TRUE;
	}
	
	return plist->count ? FALSE : TRUE;
}

BOOL list_is_full(List *plist)
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

	if (plist == NULL) {
		plist->next = node;
		node->next = NULL;
	} else {
		node->next = plist->next;
	}
}

