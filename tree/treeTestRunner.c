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

	testStarted("test_to_create_tree");
	setup();
		test_to_create_tree();
	tearDown();
	testEnded();
	testStarted("test_to_insert_root_node");
	setup();
		test_to_insert_root_node();
	tearDown();
	testEnded();
	testStarted("test_to_insert_childNode_under_root_node");
	setup();
		test_to_insert_childNode_under_root_node();
	tearDown();
	testEnded();
	testStarted("test_insert_childNodes_under_subroot_node");
	setup();
		test_insert_childNodes_under_subroot_node();
	tearDown();
	testEnded();
	testStarted("test_insert_ChildNodes_for_1st_level");
	setup();
		test_insert_ChildNodes_for_1st_level();
	tearDown();
	testEnded();
	testStarted("test_search_should_search_for_childNode_in_tree");
	setup();
		test_search_should_search_for_childNode_in_tree();
	tearDown();
	testEnded();
	testStarted("test_search_should_return_0_when_childNode_is_not_found");
	setup();
		test_search_should_return_0_when_childNode_is_not_found();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_return_0_when_tree_is_Empty");
	setup();
		test_deleteNode_should_return_0_when_tree_is_Empty();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_return_0_when_node_is_not_found");
	setup();
		test_deleteNode_should_return_0_when_node_is_not_found();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_delete_childNode_if_it_exists");
	setup();
		test_deleteNode_should_delete_childNode_if_it_exists();
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
