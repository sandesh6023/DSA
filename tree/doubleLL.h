#include "iterator.h"
typedef struct Struct_type{
	void* data;
	struct Struct_type *next;
	struct Struct_type *previous;
} Node;

typedef struct {
	int length;
	Node* head;
} List;

List* create();
int insert(List* start, int index, void* data);
void* remove(List* start, int index);
void dispose(List* start);
int isEmpty(List* start);
Iterator getIterator(List* list);