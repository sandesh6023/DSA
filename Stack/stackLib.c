#include "stackLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
Stack *create(int typeSize, int noOfElements){
	Stack *stack = malloc(sizeof(Stack));
	stack->elements = calloc(noOfElements,typeSize);
	stack->noOfElements = noOfElements;
	stack->elementSize = typeSize;
	stack->top=-1;
	return stack;
}

int isFull(Stack *stack)
{
	if(stack->top == stack->noOfElements-1) return 1;
		return 0;
}

int push(Stack *stack, void *inputElement){
	if(isFull(stack))
		return 0;

	stack->top = stack->top + 1;
	memcpy(stack->elements+(stack->top*stack->elementSize),inputElement,stack->elementSize);
		return 1;
}

void* top(Stack *stack){
	if(stack->top<0)
		return NULL;
	return stack->elements + (stack->top * stack->elementSize);	
}

void* pop(Stack *stack){
	void *removedElement;
	removedElement = top(stack);
	stack->top = stack->top-1;
		return removedElement;
}