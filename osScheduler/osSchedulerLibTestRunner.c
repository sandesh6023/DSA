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

	testStarted("test_add_first_process_to_priorityQueue");
	setup();
		test_add_first_process_to_priorityQueue();
	tearDown();
	testEnded();
	testStarted("test_sorts_processes_based_on_Process_priority");
	setup();
		test_sorts_processes_based_on_Process_priority();
	tearDown();
	testEnded();
	testStarted("test_timeSlice_fails_when_there_is_no_process_in_Queue");
	setup();
		test_timeSlice_fails_when_there_is_no_process_in_Queue();
	tearDown();
	testEnded();
	testStarted("test_timeSlice_executes_first_Process_for_10_seconds_and_changes_status");
	setup();
		test_timeSlice_executes_first_Process_for_10_seconds_and_changes_status();
	tearDown();
	testEnded();
	testStarted("test_timeSlice_removes_processs_once_the_execution_of_process_in_Queue_is_over");
	setup();
		test_timeSlice_removes_processs_once_the_execution_of_process_in_Queue_is_over();
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
