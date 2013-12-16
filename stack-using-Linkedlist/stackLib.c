#include "stackLib.h"
#include <stdio.h>
#include <stdlib.h>
// #include "./linkedListLib/doublyLinkedLib.c"


List *create()
{
	List *list = malloc(sizeof(List));
	list->head = NULL;
	list->top = 0;
	return list;
}

Node *createNode(void *element ,Node *previous,Node *next){
	Node *node = malloc(sizeof(Node));
	node->data=element;
	node->previous=previous;
	node->next = next;
	return node;
}

void insertFirstElement(List *list, void *element){
	Node *newNode;
	newNode = createNode(element,NULL,NULL);
	newNode->next = NULL;
	newNode->previous = NULL;
	list->head = newNode;
	list->top++;
}

int push(List *list,void *element){
	int i;
	Node *temp;
	Node *newNode;
	temp = list->head;

	if(list->head == NULL){
		insertFirstElement(list,element);
		return 1;
	}

	newNode = createNode(element,NULL, temp);
	temp->previous = newNode;
	list->top++;
	list->head = newNode;
	return 1;
}
int pop(List *list){
	int i;
	int index = 0;
	Node *nextNode;	
	Node *temp;
	temp = list->head;

	if(list->top==0) return 0;

	if(list->top == 1){ 
		list->head = NULL;
		list->top--;
		free(temp);
		return 1;
	}

	list->head = temp->next; 		//assign head to next element
	nextNode = temp->next;
	nextNode->previous = NULL;
	free(temp);
	list->top--;
	return 1;	

}


