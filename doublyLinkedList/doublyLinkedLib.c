#include "doublyLinkedLib.h"
#include <stdlib.h>
#include <stdio.h>

List *create()
{
	List *list = malloc(sizeof(List));
	list->head = NULL;
	list->length = 0;
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
	list->length++;
}


int insertNode(List *list,int index,void *element){
	int i;
	Node *temp;
	Node *newNode;
	temp = list->head;

	if(index>list->length) return 0 ;

	if(list->head == NULL){
		insertFirstElement(list,element);
		return 1;
	}

	for(i=0;i<list->length;i++){
		if(temp->next!=NULL)
			temp = temp->next;
	}
	newNode = createNode(element,temp, NULL);
	temp->next = newNode;
	list->length++;

	return 1;
}

int insertAfter(List *list,int index,void *element){
	int i;
	Node *temp;
	Node *newNode,*prevNode,*nextNode;
	temp = list->head;

	if(index>list->length || list->head==NULL) return 0 ;

	for(i=0;i<index;i++){
		if(temp->next!=NULL)
			temp = temp->next;
	}

	if(list->length==1 || index==list->length-1){
		newNode = createNode(element,temp,NULL);
		temp->next = newNode;
		return 1;
	}
	
	prevNode = temp;
	nextNode = temp->next;
	
	newNode = createNode(element,prevNode,nextNode);
	prevNode->next = newNode;
	nextNode->previous = newNode;
	list->length++;
	return 1;
}


int insertBefore(List *list,int index,void *element){
	int i;
	Node *temp;
	Node *newNode,*nextNode,*prevNode;
	temp = list->head;

	if(index > list->length) return 0;

	if(list->head == NULL){
		insertFirstElement(list,element);
		return 1;
	}

	if(index==0){
		newNode = createNode(element,NULL, temp);
		temp->previous = newNode;
		list->length++;
		list->head = newNode;
		return 1;
	}

	for(i=0;i<index;i++)
		if(temp->next!=NULL)
			temp = temp->next;

	prevNode = temp->previous;
	nextNode = temp;
	
	newNode = createNode(element,prevNode,nextNode);
	prevNode->next = newNode;
	nextNode->previous = newNode;
	list->length++;
	return 1; 
}


int deleteNode(List *list,int index){
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

