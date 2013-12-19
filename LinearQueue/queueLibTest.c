#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "testUtils.h"
#include "queueLib.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Queue *queuePtr;

void test_Enqueue_should_return_0_when_queue_is_full(){
	int inputElement = 33;
	int input = 17;
	int value;
	queuePtr = create(sizeof(int),2);
	value = enqueue(queuePtr,&inputElement);
	ASSERT(1==value);
	value = enqueue(queuePtr,&input);
	ASSERT(1==value);
	value = enqueue(queuePtr,&input);
	ASSERT(0==value);
}

//---------------------------Dequeue-------------------------------

void test_Dequeue_should_return_NULL_when_Queue_is_empty(){
	int inputElement = 9;
	int *result;
	queuePtr = create(sizeof(int),4);
	result = dequeue(queuePtr);
	ASSERT(NULL == result);
	free(queuePtr);
}

void test_Dequeue_should_remove_element_from_Queue(){
	int inputElement = 33;
	int input = 17;
	int result;
	int *value;
	queuePtr = create(sizeof(int),4);
	result = enqueue(queuePtr,&inputElement);
	ASSERT(1==result);
	result = enqueue(queuePtr,&input);
	ASSERT(1==result);
	
	value = dequeue(queuePtr);
	ASSERT(17==*value);
}

void test_Dequeue_should_remove_element_from_floatQueue(){
	float input = 33.23f;
	float input2 = 564.112f;
	float input3 = 88.074f;
	int result;
	float *value;
	queuePtr = create(sizeof(float),4);
	result = enqueue(queuePtr,&input);
	
	result = enqueue(queuePtr,&input2);
	result = enqueue(queuePtr,&input3);
	
	value = dequeue(queuePtr);
	ASSERT(564.112f == *value);
}

void test_Dequeue_should_remove_element_from_charQueue(){
	char inputElement = 'a';
	char input = 'b';
	char *value;
	queuePtr = create(sizeof(char),4);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input);
	
	value = dequeue(queuePtr);
	ASSERT('b'==*value);
}

void test_Dequeue_should_remove_element__and_reposition_Queue(){
	int input = 33;
	int input2 = 17;
	int input3 = 99;
	int input4 = 123;
	int input5 = 789;
	int *value;
	queuePtr = create(sizeof(int),5);
	enqueue(queuePtr,&input);
	enqueue(queuePtr,&input2);
	enqueue(queuePtr,&input3);
	enqueue(queuePtr,&input4);
	enqueue(queuePtr,&input5);

	value = dequeue(queuePtr);
	value = dequeue(queuePtr);
	value = dequeue(queuePtr);
	ASSERT(123==*value);
}
