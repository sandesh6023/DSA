#include "testUtils.h"
#include "stackLib.h"
#include <stdio.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_insert_element_into_intStack(){
	List *list;
	Node *traverseTemp;
	int insertedValue;
	int i;
	int value = 9;
	int value2 = 88;
	int value3 = 33;
	list = create();
	push(list, &value);
	push(list, &value2);
	push(list, &value3);

	traverseTemp = list->head;
	insertedValue = *(int*)traverseTemp->data;
	ASSERT(33 == insertedValue);
}

void test_insert_floatElement_into_floatStack(){
	List *list;
	Node *traverseTemp;
	float insertedValue;
	int i;
	float value = 9.23f;
	float value2 = 88.11f;
	float value3 = 33.001f;
	list = create();
	push(list, &value);
	push(list, &value2);
	push(list, &value3);

	traverseTemp = list->head;
	insertedValue = *(float*)traverseTemp->data;
	ASSERT(33.001f == insertedValue);
}
void test_insert_element_into_charStack(){
	List *list;
	Node *traverseTemp;
	char insertedValue;
	int i;
	int value = 'q';
	int value2 = 'z';
	int value3 = 't';
	list = create();
	push(list, &value);
	push(list, &value2);
	push(list, &value3);

	traverseTemp = list->head;
	insertedValue = *(char*)traverseTemp->data;
	ASSERT('t' == insertedValue);
}

void test_pop_the_element_from_Stack(){
	List *list;
	Node *traverseTemp;
	int insertedValue;
	int i;
	int value = 9;
	int value2 = 88;
	int value3 = 33;
	list = create();
	push(list, &value);
	push(list, &value2);
	push(list, &value3);

	pop(list);

	traverseTemp = list->head;
	insertedValue = *(int*)traverseTemp->data;
	ASSERT(88 == insertedValue);
}

void test_pop_should_return_0_when_stack_is_empty(){
	List *list;
	int value2 = 88;
	int value3 = 33;
	int result;
	list = create();

	push(list, &value2);
	push(list, &value3);

	pop(list);
	pop(list);
	result = pop(list);

	ASSERT(0==result);
}

void test_pop_should_pop_element_from_charStack(){
	List *list;
	Node *traverseTemp;
	char insertedValue;
	int i;
	int value = 'q';
	int value2 = 'z';
	int value3 = 't';
	list = create();
	push(list, &value);
	push(list, &value2);
	push(list, &value3);

	pop(list);

	traverseTemp = list->head;
	insertedValue = *(char*)traverseTemp->data;
	ASSERT('z' == insertedValue);
}


void test_push_string_into_StringStack(){
	List *list;
	Node *traverseTemp;
	String name1 ="san";
	String name2 = "dan";
	String name3 = "van";
	String expectedName;

	list = create();
	push(list,&name1);
	push(list,&name2);
	push(list,&name3);

	traverseTemp = list->head;
	strcpy(expectedName,*(String*)traverseTemp->data);
	ASSERT(0==strcmp("van",expectedName));
}

void test_pop_string_from_stringStack(){
	List *list;
	Node *traverseTemp;
	String name1 ="sandesh";
	String name2 = "soumya";
	String name3 = "vandal";
	String expectedName;

	list = create();
	push(list,&name1);
	push(list,&name2);
	push(list,&name3);
	
	pop(list);
	pop(list);

	traverseTemp = list->head;
	strcpy(expectedName,*(String*)traverseTemp->data);
	ASSERT(0==strcmp("sandesh",expectedName));
}

void test_add_account_balance_to_accountStack(){
	List *list;
	Node *traverseTemp;
	Account account1 = {112,10000};
	Account account2 = {113,12000};
	Account account3 = {114,20000};
	Account expectedAccount;

	push(list,&account1);
	push(list,&account2);
	push(list,&account3);

	traverseTemp = list->head;
	expectedAccount = *(Account*)traverseTemp->data;
	ASSERT(20000==expectedAccount.balance);
}