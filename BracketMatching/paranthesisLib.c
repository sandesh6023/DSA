#include "paranthesisLib.h"
#include "stackLib.h"
#include <stdio.h>
#include <string.h>
int doBracketsMatch(char *text){
	Stack *stack ;
	Stack *stack2;
	int i,j;
	int length = strlen(text);
	stack = create(sizeof(char),length);
	stack2 = create(sizeof(char),length);
	

	for(i = 0; i<length; i++)
	{
		if(text[i] == '{')
			push(stack , &text[i]);
		if(text[i]=='}')
			push(stack2,&text[i]);
	}

	if(!(stack->top==stack2->top))
		return 0;
	
	for(i = 0; i<length; i++)
	{
		if(text[i] == '[')
			push(stack , &text[i]);
		if(text[i]==']')
			push(stack2,&text[i]);
	}
	
	if(!(stack->top==stack2->top))
		return 0;
	
	for(i = 0; i<length; i++)
	{
		if(text[i] == '(')
			push(stack , &text[i]);
		if(text[i]==')')
			push(stack2,&text[i]);
	}
	if(!(stack->top==stack2->top))
		return 0;

return 1;
}