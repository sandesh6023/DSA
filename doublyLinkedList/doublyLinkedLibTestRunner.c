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

	testStarted("test_create_list_and_assign_NULL_to_head");
	setup();
		test_create_list_and_assign_NULL_to_head();
	tearDown();
	testEnded();
	testStarted("test_create_node_and_assign_values");
	setup();
		test_create_node_and_assign_values();
	tearDown();
	testEnded();
	testStarted("test_insertNode_when_linked_list_is_empty");
	setup();
		test_insertNode_when_linked_list_is_empty();
	tearDown();
	testEnded();
	testStarted("test_insertNode_should_return_0_when_index_greater_than_length");
	setup();
		test_insertNode_should_return_0_when_index_greater_than_length();
	tearDown();
	testEnded();
	testStarted("test_insertNode_at_index_1");
	setup();
		test_insertNode_at_index_1();
	tearDown();
	testEnded();
	testStarted("test_insertNode_at_index_4");
	setup();
		test_insertNode_at_index_4();
	tearDown();
	testEnded();
	testStarted("test_insertAfter_should_insert_after_index_1");
	setup();
		test_insertAfter_should_insert_after_index_1();
	tearDown();
	testEnded();
	testStarted("test_insertAfter_should_insert_after_index_1_and_connect_lastNode_to_Null");
	setup();
		test_insertAfter_should_insert_after_index_1_and_connect_lastNode_to_Null();
	tearDown();
	testEnded();
	testStarted("test_insertBefore_inserts_element_when_head_is_NULL");
	setup();
		test_insertBefore_inserts_element_when_head_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_insertBefore_inserts_element_before_present_linkedList");
	setup();
		test_insertBefore_inserts_element_before_present_linkedList();
	tearDown();
	testEnded();
	testStarted("test_insert_before_index_2_in_linked_list");
	setup();
		test_insert_before_index_2_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_return_0_when_linkedList_is_empty");
	setup();
		test_deleteNode_should_return_0_when_linkedList_is_empty();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_returns_1_on_deleting_node");
	setup();
		test_deleteNode_returns_1_on_deleting_node();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_delete_value_at_index_2");
	setup();
		test_deleteNode_should_delete_value_at_index_2();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_free_the_last_node");
	setup();
		test_deleteNode_should_free_the_last_node();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_delete_the_firstNode");
	setup();
		test_deleteNode_should_delete_the_firstNode();
	tearDown();
	testEnded();
	testStarted("test_Iterator_traverses_linkedList");
	setup();
		test_Iterator_traverses_linkedList();
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
