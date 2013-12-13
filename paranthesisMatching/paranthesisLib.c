#include "paranthesisLib.h"
#include "../Stack/stackLib.h"
#include <stdio.h>
#include <string.h>
int paranthesisMatch(char *text){
	Stack *stack;
	int i,j;
	int length = strlen(text);
	stack = create(sizeof(char),length);
	printf("%c\n",text[length-1]);
	
	if((text[0]=='{' && text[length-1]!='}') || 
		(text[0]=='(' && text[length-1]!=')')||
		(text[0]=='[' && text[length-1]!=']'))
			return 0;

	for(i = 0; i<length; i++)
	{
		if(text[i] == '{'){
			push(stack , &text[i]);
			for(j=i+1;j<length;j++)
			{
				if(text[j]=='}')
				pop(stack);
			}
		}
		if(text[i] == '['){
			push(stack , &text[i]);
			for(j=i+1;j<length;j++)
			{
				if(text[j]==']')
				pop(stack);
			}
		}
		if(text[i] == '('){
			push(stack , &text[i]);
			for(j=1;j<length;j++)
			{
				if(text[j]==')')
				pop(stack);
			}
		}
	}											//END OF FOR STATEMENT

		if(stack->top==-1)
	return 1;
return 0;
}