#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "testUtils.h"
#include "queueLib.h"
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

// Queue expectedQueue;

int areEqual(Queue a, Queue b)
{
	int result;
	result = a.elementSize==b.elementSize && a.noOfElements == b.noOfElements
				&& a.front==b.front && a.rear == b.rear;
	if(!result)	return 0;
	return 0 == memcmp(a.elements,b.elements,a.elementSize*a.noOfElements);
}

void test_create_creates_queue_of_intType(){
	int intArray[4] = {0,0,0,0};
	Queue *queuePtr;
	Queue expectedQueue = {intArray,sizeof(int),0,-1,4};
	queuePtr = create(sizeof(int),4);
	ASSERT(areEqual(expectedQueue,*queuePtr));
	free(queuePtr);
}

void test_create_creates_queue_of_charType(){
	char charArray[4] = {0,0,0,0};
	Queue *queuePtr;
	Queue expectedQueue = {charArray,sizeof(char),0,-1,4};
	queuePtr = create(sizeof(char),4);
	ASSERT(areEqual(expectedQueue,*queuePtr));
	free(queuePtr);
}

void test_create_creates_queue_of_floatType(){
	float floatArray[4] = {0.0,0.0,0.0,0.0};
	Queue *queuePtr;
	Queue expectedQueue = {floatArray,sizeof(float),0,-1,4};
	queuePtr = create(sizeof(float),4);
	ASSERT(areEqual(expectedQueue,*queuePtr));
	free(queuePtr);
}

void test_Enqueue_element_into_queue_through_rearEnd(){
	int inputElement = 9;
	Queue *queuePtr;
	int result;
	int intArray[4] = {9,0,0,0};
	Queue expectedQueue = {intArray,sizeof(int),0,0,4};
	queuePtr = create(sizeof(int),4);
	result = enqueue(queuePtr,&inputElement);
	ASSERT(areEqual(expectedQueue,*queuePtr));
}

void test_Enqueue_FloatElement_into_queue_through_rearEnd(){
	float inputElement = 9.223f;
	float input2 = 7.989f;
	Queue *queuePtr;
	int result;
	float floatArray[4] = {9.223f,7.989f,0.0,0.0};
	Queue expectedQueue = {floatArray,sizeof(float),0,1,4};
	queuePtr = create(sizeof(float),4);
	enqueue(queuePtr,&inputElement);
	result = enqueue(queuePtr,&input2);
	ASSERT(areEqual(expectedQueue,*queuePtr));
}

void test_Enqueue_element_into_charQueue_through_rearEnd(){
	char inputElement = 'd';
	Queue *queuePtr;
	int result;
	char charArray[4] = {'d',0,0,0};
	Queue expectedQueue = {charArray,sizeof(char),0,0,4};
	queuePtr = create(sizeof(char),4);
	result = enqueue(queuePtr,&inputElement);
	ASSERT(areEqual(expectedQueue,*queuePtr));
}

void test_Enqueue_element_should_return_0_if_queue_is_full(){
	int inputElement = 9;
	Queue *queuePtr;
	int result;
	// Queue expectedQueue = {intArray,sizeof(int),0,0,4};
	queuePtr = create(sizeof(int),4);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&inputElement);
	result = enqueue(queuePtr,&inputElement);
	ASSERT(0==result);
}
//---------------------------Dequeue-------------------------------

void test_Dequeue_should_return_NULL_when_Queue_is_empty(){
	int inputElement = 9;
	Queue *queuePtr;
	int *result;
	queuePtr = create(sizeof(int),4);
	result = dequeue(queuePtr);
	ASSERT(NULL == result);
}

void test_Dequeue_should_remove_element_from_Queue(){
	int inputElement = 9;
	int input = 17;
	Queue *queuePtr;
	int *value;
	queuePtr = create(sizeof(int),4);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input);
	value = dequeue(queuePtr);
	ASSERT(9==*value);
}

void test_Dequeue_should_remove_element_from_floatQueue(){
	float inputElement = 9.34;
	float input2 = 88.23;
	Queue *queuePtr;
	float *value;
	queuePtr = create(sizeof(float),4);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input2);
	dequeue(queuePtr);
	value = dequeue(queuePtr);
	ASSERT(88.23f==*value);
}

void test_Dequeue_should_remove_element_from_charQueue(){
	char inputElement = 'q';
	char input = 'j';
	Queue *queuePtr;
	char *value;
	queuePtr = create(sizeof(char),4);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input);
	value = dequeue(queuePtr);
	ASSERT('q'==*value);
}
