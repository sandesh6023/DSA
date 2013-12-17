#include "stackLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Stack *create(int noOfElements){
	Stack *stack = malloc(sizeof(Stack));
	stack->arrayOfAddresses = calloc(noOfElements,sizeof(void **));
	stack->noOfElements = noOfElements;
	stack->top=-1;
	// printf("%p\n",stack);
	return stack;
}

int isFull(Stack *stack){
	if(stack->top==stack->noOfElements-1)
		return 1;
	return 0;
}

int push(Stack *stack,void *element){
	if(isFull(stack)) {
		realloc(stack->arrayOfAddresses,stack->noOfElements*2);
		stack->noOfElements = stack->noOfElements*2;
	}
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

void *top(Stack *stack){
	if(stack->top==-1) return NULL;
	return stack->arrayOfAddresses[stack->top];
}