#include <stdio.h>
#include <string.h>
#include "list.h"

void show_cb(Node *pnode)
{
	printf("name: %s, age: %d\n", pnode->item.name, pnode->item.age);
}

int main()
{
	int opt;

	List list;
	Node node;
	
	list_init(&list);
	
	while (1) {
		printf("**************************************\n");
		printf("0) quit\n1) add item\n2) delete item\n3) show all item\nentry your choice: ");

		memset(&node, 0, sizeof(node));

		scanf("%d", &opt);
		if (opt == 1) {
			// input name
			puts("entry name: ");
			scanf("%s", node.item.name);
			
			// input age
			puts("entry age: ");
			scanf("%d", &node.item.age);
			
			// list add
			if (list_add(&list, &node) == FALSE) {
				printf("add person %s failed\n", node.item.name);
			}

		} else if (opt == 2) {
			// input name
			puts("entry name: ");
			scanf("%s", node.item.name);

			if (list_delete(&list, &node) == FALSE) {
				printf("delete person %s failed\n", node.item.name);
			}

		} else if (opt == 3) {
			list_show(&list, show_cb);

		} else {
			break;
		}
	}
	
	return 0;
}
