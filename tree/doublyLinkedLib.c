#include "doublyLinkedLib.h"
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

int removeNode(List *list,int index){
	int i;
	Node *prevNode,*nextNode;	
	Node *temp;
	temp = list->head;

	if(list->length==0) return 0;

	if(list->length == 1){ 
		list->head = NULL;
		list->length--;
		free(temp);
		return 1;
	}

	for(i=0;i<index;i++){
		if(temp->next!=NULL)
			temp = temp->next;
	}

	if(list->length-1==index)
	{	
		prevNode = temp->previous;
		prevNode->next = NULL;
		free(temp);
		list->length--;
		return 1;
	}
	if(index == 0){
		list->head = temp->next; 		//assign head to next element
		nextNode = temp->next;
		nextNode->previous = NULL;
		free(temp);
		list->length--;
		return 1;	
	}
	prevNode = temp->previous;
	nextNode = temp->next;

	prevNode->next = nextNode;
	nextNode->previous = prevNode;
	list->length--;	
	free(temp);
	return 1;
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