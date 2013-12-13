#include <stdio.h>
#include <string.h>
#include "testUtils.h"
#include "stackLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack expectedStack;

int areEqual(Stack a, Stack b)
{
	int result;
	result = a.elementSize==b.elementSize && a.noOfElements == b.noOfElements;
	if(!result)	return 0;
	return 0 == memcmp(a.elements,b.elements,a.elementSize*a.noOfElements);
}

void test_create_creates_charStack_of_size_4(){
	int value;
	Stack *stkPtr;
	char charArray[] = {0,0,0,0};
	expectedStack.elements = charArray;
	expectedStack.elementSize = 1;
	expectedStack.noOfElements = 4;
	stkPtr= create(sizeof(char),4);
	value = areEqual(expectedStack,*stkPtr);
	ASSERT(value);
	free(stkPtr);
}

void test_create_creates_intStack_of_size_4(){
	int value;
	Stack *stkPtr;
	int intArray[] = {0,0,0,0};
	expectedStack.elements = intArray;
	expectedStack.elementSize = 4;
	expectedStack.noOfElements = 4;
	stkPtr= create(sizeof(int),4);
	value = areEqual(expectedStack,*stkPtr);
	ASSERT(value);
	free(stkPtr);
}

void test_create_creates_floatStack_of_size_4(){
	Stack *stkPtr;
	float floatArray[] = {0,0,0,0};
	expectedStack.elements = floatArray;
	expectedStack.elementSize = 4;
	expectedStack.noOfElements = 4;
	stkPtr= create(sizeof(float),4);
	
	ASSERT(areEqual(expectedStack,*stkPtr));
	free(stkPtr);
}

void test_create_creates_stringStack_of_size_2(){
	Stack *stkPtr;
	String stringArray[2] = {0,0};
	expectedStack.elements = stringArray;
	expectedStack.elementSize = sizeof(String);
	expectedStack.noOfElements = 2;
	stkPtr = create(sizeof(String),2);
	
	ASSERT(areEqual(expectedStack,*stkPtr));
}

//------------------------------push-------------------------------

void test_push_integer_element_into_stack(){
	Stack *stkPtr;
	int inputValue = 5;
	int intArray[] = {5,0,0,0};
	expectedStack.elements = intArray;
	expectedStack.elementSize = sizeof(int);
	expectedStack.noOfElements = 4;
	stkPtr= create(sizeof(int),4);
	push(stkPtr,&inputValue);

	ASSERT(areEqual(expectedStack,*stkPtr));
	free(stkPtr);	
}

void test_push_char_element_into_stack(){
	Stack *stkPtr;
	char inputValue = 'c';
	char charArray[] = {'c',0,0,0};
	expectedStack.elements = charArray;
	expectedStack.elementSize = 1;
	expectedStack.noOfElements = 4;
	stkPtr= create(sizeof(char),4);
	push(stkPtr,&inputValue);

	ASSERT(areEqual(expectedStack,*stkPtr));
	free(stkPtr);	
}

void test_push_float_element_into_stack(){
	Stack *stkPtr;
	float inputValue = 5.12f;
	float floatArray[] = {5.12,0,0,0};
	expectedStack.elements = floatArray;
	expectedStack.elementSize = sizeof(float);
	expectedStack.noOfElements = 4;
	stkPtr= create(sizeof(float),4);
	push(stkPtr,&inputValue);

	ASSERT(areEqual(expectedStack,*stkPtr));
	free(stkPtr);		
}

void test_push_element_into_intStack_should_return_0_inCase_of_stackOverflow(){
	int *ptr;
	Stack *stkPtr;
	int result;
	int inputValue = 5;
	int inputValue2 = 16;
	int inputValue3 = 77;
	stkPtr = create(sizeof(int),2);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);

	result = push(stkPtr,&inputValue3);
	ASSERT(0==result);
}


//--------------------------------pop----------------------------
void test_pop_element_from_the_int_stack(){
	int *ptr;
	Stack *stkPtr;
	int inputValue = 5;
	int inputValue2 = 16;
	stkPtr = create(sizeof(int),4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	ptr = pop(stkPtr);
	ASSERT(16 == *ptr );
	free(stkPtr);
}


void test_pop_element_from_the_char_stack(){
	char *ptr;
	Stack *stkPtr;
	char inputValue = 'o';
	char inputValue2 = 'm';
	stkPtr = create(sizeof(char),4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	ptr = pop(stkPtr);
	ASSERT('m' == *ptr );
	free(stkPtr);
}

void test_pop_element_from_the_float_stack(){
	float *ptr;
	Stack *stkPtr;
	float inputValue = 99.99f;
	float inputValue2 =260.149f ;
	stkPtr = create(sizeof(float),4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	ptr = pop(stkPtr);
	ASSERT(260.149f == *ptr );
	free(stkPtr);
}

void test_pop_element_from_the_intStack_should_return_NUll_when_Stack_is_empty(){
	int *ptr;
	Stack *stkPtr;
	stkPtr = create(sizeof(int),4);
	ptr = pop(stkPtr);
	ASSERT(NULL == ptr );
	free(stkPtr);
}
//----------------------------top-------------------------------
void test_top_should_return_element_being_pointed_by_top_for_intType(){
	int *ptr;
	Stack *stkPtr;
	int inputValue = 5;
	int inputValue2 = 16;
	int inputValue3 = 99;
	stkPtr = create(sizeof(int),4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	push(stkPtr,&inputValue3);

	ptr = top(stkPtr);
	ASSERT(99 == *ptr );
}

void test_top_should_return_element_being_pointed_by_top_for_charType(){
	char *ptr;
	Stack *stkPtr;
	char inputValue = 'w';
	char inputValue2 = 'l';
	stkPtr = create(sizeof(char),4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);

	ptr = top(stkPtr);
	ASSERT('l' == *ptr );
}

void test_top_should_return_element_being_pointed_by_top_for_floatType(){
	float *ptr;
	Stack *stkPtr;
	float inputValue = 5.23f;
	float inputValue2 = 1.99f;
	float inputValue3 = 99.012f;
	stkPtr = create(sizeof(float),4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	push(stkPtr,&inputValue3);

	ptr = top(stkPtr);
	ASSERT(99.012f == *ptr );
}
void test_top_should_return_NULL_when_intStack_is_empty(){
	int *ptr;
	Stack *stkPtr;
	stkPtr = create(sizeof(int),4);
	ptr = top(stkPtr);
	ASSERT(NULL == ptr);
}