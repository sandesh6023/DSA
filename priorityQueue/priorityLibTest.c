#include "testUtils.h"
#include "priorityLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_Enqueues_elements_and_deletes_element_with_least_priority(){
	int value1 = 3;
	int value2 = 9;
	int value3 = 77;
	int value4 = 99;
	Element *recievedValue;
	Element inputValue = {10,&value1};
	Element inputValue2 = {7,&value2};
	Element inputValue3 = {17,&value3};
	Element inputValue4 = {16,&value4};

	Queue *queuePtr;
	int result;
	queuePtr = create(sizeof(Element),4);
	enqueue(queuePtr,&inputValue);
	enqueue(queuePtr,&inputValue2);
	enqueue(queuePtr,&inputValue3);
	enqueue(queuePtr,&inputValue4);

	dequeueRecord(queuePtr);
	recievedValue = (Element*)(queuePtr->elements);

	ASSERT(10==recievedValue->priority);
	ASSERT(3==*(int*)recievedValue->element);
	dequeueRecord(queuePtr);
	
	recievedValue = (Element*)(queuePtr->elements);
	ASSERT(16==recievedValue->priority);
	ASSERT(99==*(int*)recievedValue->element);

}

void test_Enqueues_StringElements_and_deletes_element_with_least_priority(){
	String value1 = "san";
	String value2 = "dan";
	String value3 = "man";
	String value4 = "van";
	Element *recievedValue;
	Element inputValue = {9,&value1};
	Element inputValue2 = {23,&value2};
	Element inputValue3 = {11,&value3};
	Element inputValue4 = {5,&value4};

	Queue *queuePtr;
	int result;
	queuePtr = create(sizeof(Element),6);
	enqueue(queuePtr,&inputValue);
	enqueue(queuePtr,&inputValue2);
	enqueue(queuePtr,&inputValue3);
	enqueue(queuePtr,&inputValue4);

	dequeueRecord(queuePtr);
	recievedValue = (Element*)(queuePtr->elements);

	ASSERT(9==recievedValue->priority);
	ASSERT(0==strcmp("san",*(String*)recievedValue->element));
	dequeueRecord(queuePtr);
	

	recievedValue = (Element*)(queuePtr->elements);
	ASSERT(11==recievedValue->priority);
	ASSERT(0==strcmp("man",*(String*)recievedValue->element));
}

