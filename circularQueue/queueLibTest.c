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
	
	int result;
	int *dequedElement;
	queuePtr = create(sizeof(int),4);
	result = enqueue(queuePtr,&inputElement);
	
	dequedElement = dequeue(queuePtr);
	ASSERT(0==*dequedElement);
}

//-------------------------------------------------------------------


void test_Enqueue_FloatElement_into_queue_through_rearEnd(){
	float inputElement = 9.223f;
	float input2 = 7.989f;
	
	float value;
	int result;
	queuePtr = create(sizeof(float),4);
	
	enqueue(queuePtr,&inputElement);
	result = enqueue(queuePtr,&input2);
	value = *(float*)(queuePtr->elements+4);
	
	ASSERT(7.989f==value);
}


void test_Enqueue_element_should_return_0_if_queue_is_full(){
	int inputElement = 9;
	int result;
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
	
	char *value;
	queuePtr = create(sizeof(char),4);
	enqueue(queuePtr,&inputElement);
	enqueue(queuePtr,&input);
	value = dequeue(queuePtr);
	ASSERT('j'==*value);
}
