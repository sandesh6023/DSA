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
	Queue expectedQueue = {intArray,sizeof(int),-1,-1,4};
	queuePtr = create(sizeof(int),4);
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

	dequeue(queuePtr);
	dequeue(queuePtr);
	value = dequeue(queuePtr);
	ASSERT(123==*value);
}

void test_inserts_three_elements_and_it_must_dequeue_for_two_times(){
	int input = 33;
	int input2 = 17;
	int input3 = 99;
	Queue *queuePtr;
	int *value;
	queuePtr = create(sizeof(int),3);
	enqueue(queuePtr,&input);
	enqueue(queuePtr,&input2);
	enqueue(queuePtr,&input3);

	dequeue(queuePtr);
	dequeue(queuePtr);
	value = dequeue(queuePtr);

	ASSERT(NULL==value);
}
void test_Enqueue_element_into_queue_through_rearEnd_and_delete_it(){
	int inputElement = 9;
	Queue *queuePtr;
	int result;
	int *dequedElement;
	queuePtr = create(sizeof(int),4);
	result = enqueue(queuePtr,&inputElement);
	
	dequedElement = dequeue(queuePtr);
	ASSERT(0==*dequedElement);
}

//-------------------------------------------------------------------

void test_create_creates_queue_of_charType(){
	char charArray[4] = {0,0,0,0};
	Queue *queuePtr;
	Queue expectedQueue = {charArray,sizeof(char),-1,-1,4};
	queuePtr = create(sizeof(char),4);
	ASSERT(areEqual(expectedQueue,*queuePtr));
	free(queuePtr);
}

void test_create_creates_queue_of_floatType(){
	float floatArray[4] = {0.0,0.0,0.0,0.0};
	Queue *queuePtr;
	Queue expectedQueue = {floatArray,sizeof(float),-1,-1,4};
	queuePtr = create(sizeof(float),4);
	ASSERT(areEqual(expectedQueue,*queuePtr));
	free(queuePtr);
}


void test_Enqueue_FloatElement_into_queue_through_rearEnd(){
	float inputElement = 9.223f;
	float input2 = 7.989f;
	Queue *queuePtr;
	float value;
	int result;
	queuePtr = create(sizeof(float),4);
	
	enqueue(queuePtr,&inputElement);
	result = enqueue(queuePtr,&input2);
	value = *(float*)(queuePtr->elements+4);
	
	ASSERT(7.989f==value);
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


void test_Dequeue_should_remove_element_from_floatQueue(){
	float inputElement = 9.34f;
	float input2 = 88.23f;
	Queue *queuePtr;
	float *value;
	queuePtr = create(sizeof(float),4);
	
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input2);
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
	ASSERT('j'==*value);
}
