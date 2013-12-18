#include "stackLib.h"

int push(List *stack,void *element){
	int index = 0;
	insertBefore(stack,index,element);
	return 1;
}

int pop(List *stack){
	int index = 0;
	return deleteNode(stack,index);
	
}
