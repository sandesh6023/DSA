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

	testStarted("test_create_creates_charStack_of_size_4");
	setup();
		test_create_creates_charStack_of_size_4();
	tearDown();
	testEnded();
	testStarted("test_create_creates_intStack_of_size_4");
	setup();
		test_create_creates_intStack_of_size_4();
	tearDown();
	testEnded();
	testStarted("test_create_creates_floatStack_of_size_4");
	setup();
		test_create_creates_floatStack_of_size_4();
	tearDown();
	testEnded();
	testStarted("test_create_creates_stringStack_of_size_2");
	setup();
		test_create_creates_stringStack_of_size_2();
	tearDown();
	testEnded();
	testStarted("test_push_integer_element_into_stack");
	setup();
		test_push_integer_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_push_char_element_into_stack");
	setup();
		test_push_char_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_push_float_element_into_stack");
	setup();
		test_push_float_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_push_element_into_intStack_should_return_0_inCase_of_stackOverflow");
	setup();
		test_push_element_into_intStack_should_return_0_inCase_of_stackOverflow();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_the_int_stack");
	setup();
		test_pop_element_from_the_int_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_the_char_stack");
	setup();
		test_pop_element_from_the_char_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_the_float_stack");
	setup();
		test_pop_element_from_the_float_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_the_intStack_should_return_NUll_when_Stack_is_empty");
	setup();
		test_pop_element_from_the_intStack_should_return_NUll_when_Stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_top_should_return_element_being_pointed_by_top_for_intType");
	setup();
		test_top_should_return_element_being_pointed_by_top_for_intType();
	tearDown();
	testEnded();
	testStarted("test_top_should_return_element_being_pointed_by_top_for_charType");
	setup();
		test_top_should_return_element_being_pointed_by_top_for_charType();
	tearDown();
	testEnded();
	testStarted("test_top_should_return_element_being_pointed_by_top_for_floatType");
	setup();
		test_top_should_return_element_being_pointed_by_top_for_floatType();
	tearDown();
	testEnded();
	testStarted("test_top_should_return_NULL_when_intStack_is_empty");
	setup();
		test_top_should_return_NULL_when_intStack_is_empty();
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
