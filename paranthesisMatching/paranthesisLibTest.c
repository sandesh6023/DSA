#include "testUtils.h"
#include "paranthesisLib.h"
#include "../Stack/stackLib.h"
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_CharStack_and_check_for_oppBrackets(){
	Stack *stack;
	int result;
	char *string = "{abcdef}";
	result = paranthesisMatch(string);
	// printf("%d\n",result);
	ASSERT(1==result);
}

void test_2create_CharStack_and_check_for_Brackets(){
	Stack *stack;
	int result;
	char *string = "{[a[b(cd)ef]}";
	result = paranthesisMatch(string);
	// printf("%d\n",result);
	ASSERT(1==result);
}

