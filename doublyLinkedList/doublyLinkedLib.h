#include "iterator.h"
typedef struct node
{
	void *data;
	struct node *previous;
	struct node *next;	
} Node;

typedef struct{
	Node *head;
	int length;
}List;

List *create();
Node *createNode(void *element ,Node *previous,Node *next);
int insertNode(List *list,int index,void *element);
int insertAfter(List *list,int index,void *element);
int insertBefore(List *list,int index,void *element);
int deleteNode(List *list,int index);
Iterator getIterator(List* list);