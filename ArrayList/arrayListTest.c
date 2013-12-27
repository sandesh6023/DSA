#include <stdlib.h>

#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 4;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_add_the_element_at_last(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	result = add(internsPtr , &tanbirka);
	ASSERT(1==result);
}

void test_Add_should_insertElement_when_ArrayList_is_empty(){
	int result;
	Intern soumya = {43343, "soumya"};
	result = add(internsPtr, &soumya);
	ASSERT(1==result);
	ASSERT(&soumya == get(internsPtr,0));
}
int cmpfunc (void * a,void * b)
{
     if( (*(int*)a - *(int*)b) == 0) return 1;
     return 0; 
}

void test_search_should_search_for_the_given_value(){
	int values[4] = {2,5,9,45};
	int result;
	int searchValue = 45;
	insert(internsPtr,0,&values[0]);
	insert(internsPtr,1,&values[1]);
	insert(internsPtr,2,&values[2]); 
	insert(internsPtr,3,&values[3]); 

	result = search(internsPtr, &searchValue,cmpfunc);
	ASSERT(1==result);
}

void test_search_should_return_0_when_list_is_empty(){
	int result;
	int value = 8;
	result = search(internsPtr,&value,cmpfunc);
	ASSERT(0==result);
}

void test_search_return_0_when_value_not_found(){
	int values[4] = {36,89,33,23};
	int result;
	int searchValue = 45;
	insert(internsPtr,0,&values[0]);
	insert(internsPtr,1,&values[1]);
	insert(internsPtr,2,&values[2]); 
	insert(internsPtr,3,&values[3]); 

	result = search(internsPtr, &searchValue,cmpfunc);
	ASSERT(0==result);
}

void test_remove_should_delete_the_element_from_list_if_exists(){
	int values[4] = {36,89,33,23};
	int result;
	int Value = 36;
	insert(internsPtr,0,&values[0]);
	insert(internsPtr,1,&values[1]);
	insert(internsPtr,2,&values[2]); 
	insert(internsPtr,3,&values[3]); 

	result = remove(internsPtr,&Value,cmpfunc);
	ASSERT(1==result);
}
