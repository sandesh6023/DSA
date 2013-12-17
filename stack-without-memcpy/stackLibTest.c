#include <stdio.h>
#include <string.h>
#include "testUtils.h"
#include "stackLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void dispose(void *arrayAddress,void *stackAddress){
	free(arrayAddress);
	free(stackAddress);
}

//------------------------------push-------------------------------
void test_push_integer_element_into_stack(){
	Stack *stkPtr;
	int *expectedValue;
	int inputValue = 5;
	stkPtr= create(4);
	push(stkPtr,&inputValue);
	// printf("%p\n",stkPtr );
	expectedValue = stkPtr->arrayOfAddresses[0];
	ASSERT(5==*expectedValue);
	dispose(stkPtr->arrayOfAddresses,stkPtr);
}

void test_push_char_element_into_stack(){
	Stack *stkPtr;
	char *expectedValue;
	char inputValue = 'c';
	char inputValue2 = 'z';

	stkPtr= create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);

	expectedValue = stkPtr->arrayOfAddresses[1];
	ASSERT('z'==*expectedValue);
}

void test_push_float_element_into_stack(){
	Stack *stkPtr;
	float *expectedValue;
	float inputValue = 5.123f;
	float inputValue2 = 88.13f;
	float inputValue3 = 221.234f;

	stkPtr= create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	push(stkPtr,&inputValue3);

	expectedValue = stkPtr->arrayOfAddresses[2];
	ASSERT(221.234f==*expectedValue);
}

void test_push_string_into_stack(){
	Stack *stkPtr;
	String *expectedValue;
	String inputValue = "san";
	String inputValue2 = "dan";
	String inputValue3 = "tan";

	stkPtr= create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	push(stkPtr,&inputValue3);

	expectedValue = stkPtr->arrayOfAddresses[2];
	ASSERT(0==strcmp("tan",*expectedValue));
}

void test_push_element_into_intStack_should_extend_stack_inCase_of_stackOverflow(){
	Stack *stkPtr;
	int inputValue = 5;
	int inputValue2 = 77;
	int expectedValue;
	stkPtr= create(2);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);

	expectedValue = *(int*)stkPtr->arrayOfAddresses[2];
	ASSERT(77==expectedValue);
}

//--------------------------------pop----------------------------
void test_pop_element_from_the_int_stack(){
	Stack *stkPtr;
	int *expectedValue;
	int inputValue = 5;
	int inputValue2 = 25;
	int inputValue3 = 59;

	stkPtr= create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	push(stkPtr,&inputValue3);

	expectedValue = pop(stkPtr);		// poping the Element
	ASSERT(59==*expectedValue);
	expectedValue = pop(stkPtr);
	ASSERT(25==*expectedValue);
}

void test_pop_element_from_the_char_stack(){
	char *ptr;
	Stack *stkPtr;
	char inputValue = 'o';
	char inputValue2 = 'm';
	stkPtr = create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	ptr = pop(stkPtr);
	ASSERT('m' == *ptr );
}

void test_pop_element_from_the_float_stack(){
	float *ptr;
	Stack *stkPtr;
	float inputValue = 99.99f;
	float inputValue2 =260.149f ;
	stkPtr = create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	ptr = pop(stkPtr);
	ASSERT(260.149f == *ptr );
}

void test_pop_element_from_the_intStack_should_return_NUll_when_Stack_is_empty(){
	int *ptr;
	Stack *stkPtr;
	stkPtr = create(4);
	ptr = pop(stkPtr);
	ASSERT(NULL == ptr );
}
//----------------------------top-------------------------------
void test_top_should_return_element_being_pointed_by_top_for_intType(){
	int *ptr;
	Stack *stkPtr;
	int inputValue = 5;
	int inputValue2 = 16;
	int inputValue3 = 99;
	stkPtr = create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	push(stkPtr,&inputValue3);

	ptr = top(stkPtr);
	ASSERT(99 == *ptr );
}

void test_top_should_return_element_being_pointed_by_top_for_charType(){
	char *expectedValue;
	Stack *stkPtr;
	char inputValue = 'w';
	char inputValue2 = 'l';
	char inputValue3 = 'u';
	stkPtr = create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	push(stkPtr,&inputValue3);

	expectedValue = top(stkPtr);
	ASSERT('u' == *expectedValue);
}

void test_top_should_return_element_being_pointed_by_top_for_floatType(){
	float *expectedValue;
	Stack *stkPtr;
	float inputValue = 5.23f;
	float inputValue2 = 1.99f;
	float inputValue3 = 99.012f;
	stkPtr = create(4);
	push(stkPtr,&inputValue);
	push(stkPtr,&inputValue2);
	push(stkPtr,&inputValue3);

	expectedValue = top(stkPtr);
	ASSERT(99.012f == *expectedValue);
}

void test_top_should_return_NULL_when_intStack_is_empty(){
	int *ptr;
	Stack *stkPtr;
	stkPtr = create(4);
	ptr = top(stkPtr);
	ASSERT(NULL == ptr);
}


// void test_create_creates_intStack_of_size_4(){
// 	int i;
// 	int result;
// 	int value = 9;
// 	int value2 =10;
// 	int value3 = 90;
// 	int value4 = 99;
// 	Stack *stkPtr;
// 	stkPtr= create(4);
// 	push(stkPtr,&value);
// 	push(stkPtr,&value2);
// 	push(stkPtr,&value3);
// 	push(stkPtr,&value4);
// 	for(i=0;i<4;i++)
// 		printf("%d\n",*(int*)stkPtr->arrayOfAddresses[i]);
	
// 	result = push(stkPtr,&value4);
// 	ASSERT(0==result);
// }

// void test_pop_pops_element_from_stack(){
// int i;
// 	int *result;
// 	int value = 9;
// 	int value2 =10;
// 	int value3 = 90;
// 	int value4 = 99;
// 	Stack *stkPtr;
// 	stkPtr= create(4);
// 	push(stkPtr,&value);
// 	push(stkPtr,&value2);
// 	push(stkPtr,&value3);
// 	push(stkPtr,&value4);
// 	for(i=0;i<4;i++)
// 		printf("%d\n",*(int*)stkPtr->arrayOfAddresses[i]);
	
// 	result = pop(stkPtr);
// 	ASSERT(99==*result);

// }