#include "doubleLL.h"
#include <stdlib.h>
#include <stdlib.h>

List* create(){
	List* start = calloc(1,sizeof(List));
	start->length=0;
	start->head=NULL;
	return start;
}

Node* createNode(void* prevAddress,void* nextAddress){
	Node* newNode =  calloc(1, sizeof(Node));
	newNode->next = nextAddress;
	newNode->previous = prevAddress;
	return newNode;
}

int insert(List *start, int index, void *data){
	Node *head=NULL,*prev=NULL,*next=NULL;
	int i;
	head = start->head;
    while(head!= NULL){
        prev = head;
        head = head->next;
    }
    head = prev;
	if(start->length==0){
		start->head = createNode(prev, next);;
		start->head->data=data;
		start->length++;	
		return 1;
	}
	if(start->length == index){
        head->next = createNode(prev, next);
        head->next->data = data;
        start->length++;
        return 1;
	}
	if(index >= 0 && index < start->length){
		int count;
		head = start->head;
		prev = head->previous;
		next = head;
		if(index == 0){
			start->head = createNode(prev, next);
			start->head->data = data;
			start->length++;
			return 1;
		}
		for (count = 0; count < index-1; ++count)
		{
			head = head->next;
		}
		prev = head;
		next = head->next;
		head->next = createNode(prev, next);
		head->next->data = data;
		start->length++;

	}
	return 1;	
}

void* remove(List *start, int index){
	Node *temp,*temp2;
	int count = 1;
	if(index >= start->length)
		return NULL;
	if(index == 0){
		temp = start->head->data;
		start->head = start->head->next;
		start->length--;
		return temp;
	}
	temp = start->head;
	while(count < index){
		temp = temp->next;
		count++;
	}
	temp2=temp->next;
	temp->next = temp->next->next;
	if(temp->next != NULL)
		temp->next->previous = temp;
	start->length--;
	return temp2->data;
}

void dispose(List* start){
	Node* temp = start->head;
	Node* t1 = temp ;
	int count = 0;
	while(t1 != NULL){
		if(count != 0)
			temp = t1;
		t1 = temp->next;
		if (temp != NULL)
			free(temp);
		count++;
	}
}

int isEmpty(List* start){
	if(start->head == NULL)
		return 1;
	return 0;
}

int hasnext(Iterator* it){
	Node* temp = ((List*)it->list)->head;
	int count;
	for(count = 0; count < (it->position+1); count++){
		temp = temp->next;
	}
	if(temp != NULL)
		return 1;
	return 0;
}

void* next(Iterator* it){
	Node* temp = ((List*)it->list)->head;
	int count;
	++it->position;
	for(count = 0 ; count < it->position ; count++ ){
		temp = temp->next;
	}
	return temp->data;
}


Iterator getIterator(List* list){
	Iterator iterator;
	iterator.position = -1;
	iterator.list = list;
	iterator.hasNext = hasnext;
	iterator.next = next;
	return iterator;
}