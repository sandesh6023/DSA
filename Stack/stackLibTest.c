#include <stdio.h>
#include <string.h>
#include "testUtils.h"
#include "stackLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack *stkPtr;

void test_push_element_into_intStack_should_return_0_inCase_of_stackOverflow(){
	int *ptr;
	// Stack *stkPtr;
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
	// Stack *stkPtr;
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
	// Stack *stkPtr;
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
	// Stack *stkPtr;
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
	// Stack *stkPtr;
	stkPtr = create(sizeof(int),4);
	ptr = pop(stkPtr);
	ASSERT(NULL == ptr );
	free(stkPtr);
}
//----------------------------top-------------------------------
void test_top_should_return_element_being_pointed_by_top_for_intType(){
	int *ptr;
	// Stack *stkPtr;
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
	// Stack *stkPtr;
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
	// Stack *stkPtr;
	stkPtr = create(sizeof(int),4);
	ptr = top(stkPtr);
	ASSERT(NULL == ptr);
}