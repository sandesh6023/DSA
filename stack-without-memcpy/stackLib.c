#include "stackLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Stack *create(int noOfElements){
	Stack *stack = malloc(sizeof(Stack));
	stack->arrayOfAddresses = calloc(noOfElements,sizeof(void **));
	stack->noOfElements = noOfElements;
	stack->top=-1;
	return stack;
}

int isFull(Stack *stack){
	if(stack->top==stack->noOfElements-1)
		return 1;
	return 0;
}

int push(Stack *stack,void *element){
	if(isFull(stack)) return 0;
	stack->top++;
	stack->arrayOfAddresses[stack->top] = element;
	return 1;
}

int isEmpty(Stack *stack){
	if(stack->top==-1) return 1;
		return 0;
}

void *pop(Stack *stack){
	void **poppedElement;
	if(isEmpty(stack)) 
		return NULL;
	poppedElement = stack->arrayOfAddresses[stack->top];
	stack->top--;
	return poppedElement;
}