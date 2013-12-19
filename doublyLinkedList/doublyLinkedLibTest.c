#include "testUtils.h"
#include "doublyLinkedLib.h"
#include <stdio.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

List *list;

int areEqual(List a, List b)
{
	return a.head == b.head && a.length == b.length;
}

int areEqual2(Node a, Node b)
{
	return a.data == b.data && a.next == b.next && a.previous == b.previous;
}

void test_create_list_and_assign_NULL_to_head(){
	List expectedList;
	
	expectedList.length = 0;
	expectedList.head = NULL;
	list = create();
	ASSERT(areEqual(expectedList,*list));
	free(list);
}

void test_create_node_and_assign_values(){
	int value = 6;
	Node *node;
	Node expectedNode;
	expectedNode.data = &value;
	expectedNode.next = NULL;
	expectedNode.previous = NULL;
	node = createNode(&value,NULL,NULL);
	ASSERT(areEqual2(expectedNode,*node));
	free(node);

}

void test_insertNode_when_linked_list_is_empty(){
	
	int element = 9;
	int *insertedValue;
	list = create();
	insertNode(list,0,&element);
	insertedValue = (int *)list->head->data;
	ASSERT(9==*insertedValue);
	free(list);

}

void test_insertNode_should_return_0_when_index_greater_than_length(){
	
	int value;
	int element = 9;
	list = create();
	insertNode(list,0,&element);
	value = insertNode(list, 2, &element);
	
	ASSERT(0==value);
	free(list);

}

void test_insertNode_at_index_1(){
	
	Node *traverseTemp;
	int element = 9;
	int element2 = 23;
	int *insertedValue;
	list = create();
	insertNode(list,0,&element);
	insertNode(list,1,&element2); 

	traverseTemp = list->head;
	traverseTemp = traverseTemp->next;
	// printf("%d\n",*(int*)traverseTemp->data);
	insertedValue = (int*)traverseTemp->data;
	ASSERT(23 == *insertedValue);
}


void test_insertNode_at_index_4(){
	
	int i;
	Node *traverseTemp;
	int element = 9;
	int element2 = 23;
	int element3 = 46;
	int element4 = 99;
	int element5 = 221;
	int *insertedValue;
	list = create();
	insertNode(list,0,&element);
	insertNode(list,1,&element2); 
	insertNode(list,2,&element3); 
	insertNode(list,3,&element4); 
	insertNode(list,4,&element5); 
	
	traverseTemp = list->head;
	for(i=0;i<4;i++)
		traverseTemp = traverseTemp->next;	

	insertedValue = (int*)traverseTemp->data;
	ASSERT(221 == *insertedValue);
}

void test_insertAfter_should_insert_after_index_1(){
	
	int i;
	Node *traverseTemp;
	int element = 9;
	int element2 = 23;
	int element3 = 46;
	int element4 = 99;
	int *insertedValue;
	list = create();
	insertNode(list,0,&element);
	insertNode(list,1,&element2); 
	insertNode(list,2,&element3); 
	
	insertAfter(list,1,&element4);

	traverseTemp = list->head;
	for(i=0;i<2;i++)
		traverseTemp = traverseTemp->next;	

	insertedValue = (int*)traverseTemp->data;
	ASSERT(99 == *insertedValue);

}

void test_insertAfter_should_insert_after_index_1_and_connect_lastNode_to_Null(){
	
	int i;
	Node *traverseTemp;
	int element = 9;
	int element2 = 23;
	int element3 = 97;
	int *insertedValue;
	list = create();
	insertNode(list,0,&element);
	insertNode(list,1,&element2); 
	
	insertAfter(list,1,&element3);

	traverseTemp = list->head;
	for(i=0;i<2;i++)
		traverseTemp = traverseTemp->next;	

	insertedValue = (int*)traverseTemp->data;
	ASSERT(97 == *insertedValue);
	ASSERT(NULL == traverseTemp->next);
}


void test_insertBefore_inserts_element_when_head_is_NULL(){
	
	int element = 9;
	int *insertedValue;
	list = create();
	insertBefore(list,0,&element);
	insertedValue = (int *)list->head->data;
	ASSERT(9==*insertedValue);	
}

void test_insertBefore_inserts_element_before_present_linkedList(){
	
	int element = 9;
	int element2 = 44;
	int *insertedValue;
	list = create();
	insertNode(list,0,&element);
	insertBefore(list,0,&element2);

	insertedValue = (int *)list->head->data;
	ASSERT(44==*insertedValue);	
}

void test_insert_before_index_2_in_linked_list(){
	
	int i;
	Node *traverseTemp;
	int *insertedValue;

	int element = 9;
	int element2 = 23;
	int element3 = 46;
	int element4 = 99;
	int element5 = 88;
	list = create();
	insertNode(list,0,&element);
	insertNode(list,1,&element2); 
	insertNode(list,2,&element3); 
	insertNode(list,3,&element4); 
		
	insertBefore(list,2,&element5);
	traverseTemp = list->head;
	for(i=0;i<2;i++)
		traverseTemp = traverseTemp->next;	
		insertedValue =(int*)traverseTemp->data ;

	ASSERT(88==*insertedValue);
}

void test_deleteNode_should_return_0_when_linkedList_is_empty(){
	
	int value;
	list = create();
	value = deleteNode(list,0);
	ASSERT(0==value);
}

void test_deleteNode_returns_1_on_deleting_node(){
	
	int value;
	int element = 9;
	list = create();
	insertNode(list,0,&element);
	value = deleteNode(list,0);
	ASSERT(1==value);
}

void test_deleteNode_should_delete_value_at_index_2(){
	
	int i;
	Node *traverseTemp;
	int *insertedValue;

	int element = 9;
	int element2 = 23;
	int element3 = 46;
	int element4 = 99;
	
	list = create();
	insertNode(list,0,&element);
	insertNode(list,1,&element2); 
	insertNode(list,2,&element3); 
	insertNode(list,3,&element4); 

	deleteNode(list,2);

	traverseTemp = list->head;
	for(i=0;i<2;i++)
		traverseTemp = traverseTemp->next;	
	insertedValue =(int*)traverseTemp->data ;
	ASSERT(99==*insertedValue);
}

void test_deleteNode_should_free_the_last_node(){
	
	int i;
	Node *traverseTemp;
	int *insertedValue;

	int element = 9;
	int element2 = 23;
	int element3 = 46;
	int element4 = 99;
	
	list = create();
	insertNode(list,0,&element);
	insertNode(list,1,&element2); 
	insertNode(list,2,&element3); 
	insertNode(list,3,&element4); 

	deleteNode(list,3);

	traverseTemp = list->head;
	for(i=0;i<2;i++)
		traverseTemp = traverseTemp->next;	
	// insertedValue =(int*)traverseTemp->data ;
	ASSERT(NULL==traverseTemp->next);
}

void test_deleteNode_should_delete_the_firstNode(){
	
	int i;
	Node *traverseTemp;
	int *insertedValue;

	int element = 9;
	int element2 = 23;
	int element3 = 46;
	int element4 = 99;
	
	list = create();
	insertNode(list,0,&element);
	insertNode(list,1,&element2); 
	insertNode(list,2,&element3); 
	insertNode(list,3,&element4); 

	deleteNode(list,0);

	traverseTemp = list->head;
	insertedValue =(int*)traverseTemp->data ;
	ASSERT(23==*insertedValue);
}