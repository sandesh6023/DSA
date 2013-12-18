#include "testUtils.h"
#include "stackLib.h"
#include <stdio.h>
#include <string.h>
// #include "doublyLinkedLib.o"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_insert_element_into_intStack(){
	List *stack;
	Node *traverseTemp;
	int insertedValue;
	int i;
	int value = 9;
	int value2 = 88;
	int value3 = 33;
	stack = create();
	
	push(stack,&value);
	push(stack,&value2);
	push(stack,&value3);

	traverseTemp = stack->head;
	insertedValue = *(int*)traverseTemp->data;
	ASSERT(33 == insertedValue);
}

void test_deleteNode_the_element_from_Stack(){
	List *stack;
	Node *traverseTemp;
	int insertedValue;
	int i;
	int value = 9;
	int value2 = 88;
	int value3 = 33;
	stack = create();
	
	push(stack,&value);
	push(stack,&value2);
	push(stack,&value3);

	pop(stack);

	traverseTemp = stack->head;
	insertedValue = *(int*)traverseTemp->data;
	ASSERT(88 == insertedValue);
}

void test_deleteNode_should_return_0_when_stack_is_empty(){
	List *stack;
	int value2 = 88;
	int value3 = 33;
	int result;
	stack = create();

	push(stack,&value2);
	push(stack,&value3);


	pop(stack);
	pop(stack);

	result = pop(stack);

	ASSERT(0==result);
}

void test_insertBefore_string_into_StringStack(){
	List *stack;
	Node *traverseTemp;
	String name1 ="san";
	String name2 = "dan";
	String name3 = "van";
	String expectedName;

	stack = create();
	push(stack,&name1);
	push(stack,&name2);
	push(stack,&name3);

	traverseTemp = stack->head;
	strcpy(expectedName,*(String*)traverseTemp->data);
	ASSERT(0==strcmp("van",expectedName));
}

void test_deleteNode_string_from_stringStack(){
	List *stack;
	Node *traverseTemp;
	String name1 ="sandesh";
	String name2 = "soumya";
	String name3 = "vandal";
	String expectedName;

	stack = create();

	push(stack,&name1);
	push(stack,&name2);
	push(stack,&name3);
	
	pop(stack);
	pop(stack);

	traverseTemp = stack->head;
	strcpy(expectedName,*(String*)traverseTemp->data);
	ASSERT(0==strcmp("sandesh",expectedName));
}

void test_add_account_balance_to_accountStack(){
	List *stack;
	Node *traverseTemp;
	Account account1 = {112,10000};
	Account account2 = {113,12000};
	Account account3 = {114,20000};
	Account expectedAccount;

	push(stack,&account1);
	push(stack,&account2);
	push(stack,&account3);

	traverseTemp = stack->head;
	expectedAccount = *(Account*)traverseTemp->data;
	ASSERT(20000==expectedAccount.balance);
}