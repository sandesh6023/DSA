#include "iterator.h"

typedef struct node{
	void* data;
	struct node *next;
	struct node *previous;
} Node;

typedef struct {
	int length;
	Node* head;
} List;

List* create();
int insert(List* start, int index, void* data);
void* removeNode(List* start, int index);
void dispose(List* start);
int isEmpty(List* start);
Iterator getIterator(List* list);