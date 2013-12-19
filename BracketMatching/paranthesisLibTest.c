#include "testUtils.h"
#include "paranthesisLib.h"
#include "stackLib.h"
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_CharStack_and_check_for_oppBrackets(){
	Stack *stack;
	int result;
	char *string = "{abcdef}";
	result = doBracketsMatch(string);
	ASSERT(1==result);
}

void test_2create_CharStack_and_check_for_Brackets(){
	Stack *stack;
	int result;
	char *string = "{[a[b(cd)ef]}";
	result = doBracketsMatch(string);
	ASSERT(0==result);
}

void test_3create_CharStack_and_check_for_Brackets(){
	Stack *stack;
	int result;
	char *string = "[a[b(cd)ef]}";
	result = doBracketsMatch(string);
	ASSERT(0==result);
}

void test_4create_CharStack_and_check_for_Brackets(){
	Stack *stack;
	int result;
	char *string = "{[[]}";
	result = doBracketsMatch(string);
	ASSERT(0==result);
}
