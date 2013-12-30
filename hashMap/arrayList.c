#include "arrayList.h"
#include <stdlib.h>
#include "Iterator.h"
ArrayList create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
	}	
}

int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int insert(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;

	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);

	list->base[index] = data;
	list->length++;

	return 1;
}

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
}

int add(ArrayList *list,void *data){
	if(list->length == 0){
		insert(list,0, data);
		return 1;
	}	
	list->base[list->length] = data;
	list->length++;
	return 1;
}

void disposeList(ArrayList *list) {
	free(list->base);
}

int search(ArrayList *list,void *searchValue,compareFunc comp){
	int i;
	if(list->length==0) return 0;
	
	for(i=0;i<list->length;i++){
	 	if(comp(list->base[i],searchValue)==1)
	 		return 1;
	}
	return 0;
}
void shiftElements(ArrayList *list,int index){
	for(index = 0; index<list->length; index++)
		list->base[index] = list->base[index +1];
}

int remove(ArrayList *list,void *value,compareFunc comp){
	int i;
	for(i=0;i<list->length;i++){
	 	if(comp(list->base[i],value)==1){
	 		shiftElements(list,i);
	 		return 1;
	 	}
	}
	return 0;
}

int hasnext(Iterator* it){
    ArrayList* temp = (ArrayList*)it->list;
    if(temp->base[it->position+1] != NULL)
            return 1;
    return 0;
}

void* accessNextElement(Iterator* it){
    ArrayList* temp = (ArrayList*)it->list;
    return temp->base[++it->position];        
}

Iterator getIterator(ArrayList* list){
    Iterator it;
    it.position = -1;
    it.list = list;
    it.hasNext = hasnext;
    it.next = accessNextElement;
    return it;
}