#include "testUtils.h"
#include "stackLib.h"
#include <stdio.h>
#include <string.h>
// #include "doublyLinkedLib.o"

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
	insertBefore(list,0,&value);
	insertBefore(list,0,&value2);
	insertBefore(list,0,&value3);

	traverseTemp = list->head;
	insertedValue = *(int*)traverseTemp->data;
	ASSERT(33 == insertedValue);
}

void test_deleteNode_the_element_from_Stack(){
	List *list;
	Node *traverseTemp;
	int insertedValue;
	int i;
	int value = 9;
	int value2 = 88;
	int value3 = 33;
	list = create();
	insertBefore(list,0, &value);
	insertBefore(list,0, &value2);
	insertBefore(list,0, &value3);

	deleteNode(list,0);

	traverseTemp = list->head;
	insertedValue = *(int*)traverseTemp->data;
	ASSERT(88 == insertedValue);
}

void test_deleteNode_should_return_0_when_stack_is_empty(){
	List *list;
	int value2 = 88;
	int value3 = 33;
	int result;
	list = create();

	insertBefore(list,0, &value2);
	insertBefore(list,0, &value3);

	deleteNode(list,0);
	deleteNode(list,0);

	result = deleteNode(list,0);

	ASSERT(0==result);
}

void test_insertBefore_string_into_StringStack(){
	List *list;
	Node *traverseTemp;
	String name1 ="san";
	String name2 = "dan";
	String name3 = "van";
	String expectedName;

	list = create();
	insertBefore(list,0,&name1);
	insertBefore(list,0,&name2);
	insertBefore(list,0,&name3);

	traverseTemp = list->head;
	strcpy(expectedName,*(String*)traverseTemp->data);
	ASSERT(0==strcmp("van",expectedName));
}

void test_deleteNode_string_from_stringStack(){
	List *list;
	Node *traverseTemp;
	String name1 ="sandesh";
	String name2 = "soumya";
	String name3 = "vandal";
	String expectedName;

	list = create();
	insertBefore(list,0,&name1);
	insertBefore(list,0,&name2);
	insertBefore(list,0,&name3);
	
	deleteNode(list,0);
	deleteNode(list,0);

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

	insertBefore(list,0,&account1);
	insertBefore(list,0,&account2);
	insertBefore(list,0,&account3);

	traverseTemp = list->head;
	expectedAccount = *(Account*)traverseTemp->data;
	ASSERT(20000==expectedAccount.balance);
}