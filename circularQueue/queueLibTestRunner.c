#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_Enqueue_should_return_0_when_queue_is_full");
	setup();
		test_Enqueue_should_return_0_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_Dequeue_should_return_NULL_when_Queue_is_empty");
	setup();
		test_Dequeue_should_return_NULL_when_Queue_is_empty();
	tearDown();
	testEnded();
	testStarted("test_Dequeue_should_remove_element_from_Queue");
	setup();
		test_Dequeue_should_remove_element_from_Queue();
	tearDown();
	testEnded();
	testStarted("test_Dequeue_should_remove_element__and_reposition_Queue");
	setup();
		test_Dequeue_should_remove_element__and_reposition_Queue();
	tearDown();
	testEnded();
	testStarted("test_inserts_three_elements_and_it_must_dequeue_for_two_times");
	setup();
		test_inserts_three_elements_and_it_must_dequeue_for_two_times();
	tearDown();
	testEnded();
	testStarted("test_Enqueue_element_into_queue_through_rearEnd_and_delete_it");
	setup();
		test_Enqueue_element_into_queue_through_rearEnd_and_delete_it();
	tearDown();
	testEnded();
	testStarted("test_Enqueue_FloatElement_into_queue_through_rearEnd");
	setup();
		test_Enqueue_FloatElement_into_queue_through_rearEnd();
	tearDown();
	testEnded();
	testStarted("test_Enqueue_element_should_return_0_if_queue_is_full");
	setup();
		test_Enqueue_element_should_return_0_if_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_Dequeue_should_remove_element_from_floatQueue");
	setup();
		test_Dequeue_should_remove_element_from_floatQueue();
	tearDown();
	testEnded();
	testStarted("test_Dequeue_should_remove_element_from_charQueue");
	setup();
		test_Dequeue_should_remove_element_from_charQueue();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
