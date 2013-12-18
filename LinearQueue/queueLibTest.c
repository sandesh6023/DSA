#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "testUtils.h"
#include "queueLib.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


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
//-------------------------------------------------------

void test_Enqueue_element_into_queue_through_rearEnd(){
	int inputElement = 9;
	Queue *queuePtr;
	int result;
	int intArray[4] = {9,0,0,0};
	Queue expectedQueue = {intArray,sizeof(int),0,0,4};
	queuePtr = create(sizeof(int),4);
	result = enqueue(queuePtr,&inputElement);
	// printf("%d\n",*(int*)queuePtr->elements );
	ASSERT(areEqual(expectedQueue,*queuePtr));
}


void test_Enqueue_element_into_queue_through_rearEnd_for_charType(){
	char inputElement = 'c';
	Queue *queuePtr;
	int result;
	char charArray[4] = {'c',0,0,0};
	Queue expectedQueue = {charArray,sizeof(char),0,0,4};
	queuePtr = create(sizeof(char),4);
	result = enqueue(queuePtr,&inputElement);
	ASSERT(areEqual(expectedQueue,*queuePtr));
}


void test_Enqueue_element_into_queue_through_rearEnd_floatType(){
	float inputElement = 9.23f;
	Queue *queuePtr;
	int result;
	float floatArray[4] = {9.23f,0,0,0};
	Queue expectedQueue = {floatArray,sizeof(float),0,0,4};
	queuePtr = create(sizeof(float),4);
	result = enqueue(queuePtr,&inputElement);
	ASSERT(areEqual(expectedQueue,*queuePtr));
}
void test_Enqueue_should_return_0_when_queue_is_full(){
	int inputElement = 33;
	int input = 17;
	int value;
	Queue *queuePtr;
	queuePtr = create(sizeof(int),2);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input);
	value = enqueue(queuePtr,&input);
	ASSERT(0==value);
}

//---------------------------Dequeue-------------------------------

void test_Dequeue_should_return_NULL_when_Queue_is_empty(){
	int inputElement = 9;
	Queue *queuePtr;
	int *result;
	queuePtr = create(sizeof(int),4);
	result = dequeue(queuePtr);
	ASSERT(NULL == result);
	free(queuePtr);
}

void test_Dequeue_should_remove_element_from_Queue(){
	int inputElement = 33;
	int input = 17;
	Queue *queuePtr;
	int *value;
	queuePtr = create(sizeof(int),4);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input);
	
	value = dequeue(queuePtr);
	ASSERT(17==*value);
}

void test_Dequeue_should_remove_element_from_floatQueue(){
	float input = 33.23f;
	float input2 = 564.112f;
	float input3 = 88.074f;
	Queue *queuePtr;
	float *value;
	queuePtr = create(sizeof(float),4);
	enqueue(queuePtr,&input);
	enqueue(queuePtr,&input2);
	enqueue(queuePtr,&input3);
	
	value = dequeue(queuePtr);
	ASSERT(564.112f == *value);
}

void test_Dequeue_should_remove_element_from_charQueue(){
	char inputElement = 'a';
	char input = 'b';
	Queue *queuePtr;
	char *value;
	queuePtr = create(sizeof(char),4);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input);
	
	value = dequeue(queuePtr);
	// printf("%c\n",*value );
	ASSERT('b'==*value);
}

void test_Dequeue_should_remove_element__and_reposition_Queue(){
	int input = 33;
	int input2 = 17;
	int input3 = 99;
	int input4 = 123;
	int input5 = 789;
	Queue *queuePtr;
	int *value;
	queuePtr = create(sizeof(int),5);
	enqueue(queuePtr,&input);
	enqueue(queuePtr,&input2);
	enqueue(queuePtr,&input3);
	enqueue(queuePtr,&input4);
	enqueue(queuePtr,&input5);

	value = dequeue(queuePtr);
	// printf("%d\n",*value );
	value = dequeue(queuePtr);
	// printf("%d\n",*value );
	value = dequeue(queuePtr);
	// printf("rear====>%d\n\n======>%d\n",queuePtr->rear,*value );
	ASSERT(123==*value);
}
