#include "../../iterator.h"
typedef struct{
	void** base;
	int capacity;
	int length;
}ArrayList;
typedef int (*compare) (void *valueToBeSearch, void* element);
ArrayList createList(int capacity);
int addIntoList(ArrayList* list, void* data);
int insertIntoList(ArrayList* list, int index, void* data);
void* get(ArrayList* list, int index);
int removeFromList(ArrayList* list, int index);
int search (ArrayList* list, compare areEqual,void* elementToBeSearch);
void disposeList(void* ptr);
Iterator getIteratorOfArrayList(ArrayList* list);