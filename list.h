#ifndef __LIST_H_
#define __LIST_H_

typedef enum bool_em {
	FALSE = 0,
	TRUE = 1
} BOOL;

#define MAX_NAME_LEN 128

typedef struct person_st {
	char name[MAX_NAME_LEN];
	int age;
} ITEM;

typedef struct node_st {
	ITEM item;
	struct node_st *next;	
} Node; 

typedef struct list_st {
	Node *node;	
	int count;
} List;

// init list 
void list_init(List *plist);

// list is empty
BOOL list_is_empty(const List *plist);

// list is full
BOOL list_is_full(const List *plist);

// list add 
BOOL list_add(List *plist, Node *pnode);

// list delete
BOOL list_delete(List *plist, Node *pnode);

// list show
void list_show(const List *plist, void (*show_cb)(Node *pnode)); 

// list find 
BOOL list_find(List *plist, Node *pnode);

// list count
int list_count(const List *plist);
#endif
