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

	testStarted("test_insert_element_into_intStack");
	setup();
		test_insert_element_into_intStack();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_the_element_from_Stack");
	setup();
		test_deleteNode_the_element_from_Stack();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_return_0_when_stack_is_empty");
	setup();
		test_deleteNode_should_return_0_when_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_insertBefore_string_into_StringStack");
	setup();
		test_insertBefore_string_into_StringStack();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_string_from_stringStack");
	setup();
		test_deleteNode_string_from_stringStack();
	tearDown();
	testEnded();
	testStarted("test_add_account_balance_to_accountStack");
	setup();
		test_add_account_balance_to_accountStack();
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
