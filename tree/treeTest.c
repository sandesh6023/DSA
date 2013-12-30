#include <stdio.h>
#include "testUtils.h"
#include "tree.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int comparator(void* ID, void* data){
	return *(int*)ID == *(int*)data;
}

Tree tree;

void test_to_create_tree(){
	tree = createTree(comparator);
	ASSERT(NULL == tree.root);
	ASSERT(comparator == tree.cmp);
}

void test_to_insert_root_node(){
	int result;
	int parentNode = 6;
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&parentNode);
	ASSERT(1 == result);
}

void test_to_insert_childNode_under_root_node(){
	int result;
	int arr[] = {1,2,3};
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&arr[0]);
	ASSERT(1 == result);
	result = insertNode(&tree, &arr[0], &arr[1]);
	ASSERT(1== result);
}

void test_insert_childNodes_under_subroot_node(){
	int result;
	int values[] = {1,2,3,4};
	Iterator it;
	void *temp;
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&values[0]);
	ASSERT(1 == result);
	insertNode(&tree, &values[0], &values[1]);
	insertNode(&tree, &values[0], &values[2]);
	result = insertNode(&tree, &values[0], &values[3]);

	ASSERT(1== result);

	it = getChildren(&tree, &values[0]);	// Traversing childNodes
	temp = it.next(&it);
	ASSERT(4==*(int*)temp);

	temp = it.next(&it);
	ASSERT(3==*(int*)temp);

	temp = it.next(&it);
	ASSERT(2==*(int*)temp);
}

void test_insert_ChildNodes_for_1st_level(){
	int result;
	void *temp;
	int values[] = {1,2,3,4,10,11,14};
	Iterator it;
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&values[0]);
	ASSERT(1 == result);
	insertNode(&tree, &values[0], &values[1]);
	insertNode(&tree, &values[0], &values[2]);
	insertNode(&tree, &values[0], &values[3]);
	result = insertNode(&tree,&values[3],&values[4]);
	ASSERT(1==result);
	insertNode(&tree,&values[4],&values[5]);

	it = getChildren(&tree,&values[4]);
	temp = it.next(&it);
	ASSERT(11==*(int*)temp);
}

void test_search_should_search_for_childNode_in_tree(){
	int result;
	int values[] = {1,2,3,4};
	int searchValue = 3;
	Iterator it;
	void *temp;
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&values[0]);
	ASSERT(1 == result);
	result = insertNode(&tree, &values[0], &values[1]);
	result = insertNode(&tree, &values[0], &values[2]);
	result = insertNode(&tree, &values[0], &values[3]);

	ASSERT(1== result);
	result = search(&tree, &searchValue);
	ASSERT(1==result);
}

void test_search_should_return_0_when_childNode_is_not_found(){
	int result;
	int values[] = {1,2,3,4};
	int searchValue = 9;
	Iterator it;
	void *temp;
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&values[0]);
	ASSERT(1 == result);
	insertNode(&tree, &values[0], &values[1]);
	insertNode(&tree, &values[0], &values[2]);
	result = insertNode(&tree, &values[0], &values[3]);

	ASSERT(1== result);
	result = search(&tree, &searchValue);
	ASSERT(0==result);
}

void test_deleteNode_should_return_0_when_tree_is_Empty(){
	int result;
	int data = 9;
	tree = createTree(comparator);
	result = deleteNode(&tree,&data);
	ASSERT(0==result);
}

void test_deleteNode_should_return_0_when_node_is_not_found(){
	int result;
	int values[] = {1,2,3,4};
	int valueToBeDeleted = 9;
	Iterator it;
	void *temp;
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&values[0]);
	ASSERT(1 == result);
	insertNode(&tree, &values[0], &values[1]);
	insertNode(&tree, &values[0], &values[2]);
	insertNode(&tree, &values[0], &values[3]);
	result = deleteNode(&tree,&valueToBeDeleted);
	ASSERT(0==result);
}

void test_deleteNode_should_delete_childNode_if_it_exists(){
	int result;
	int values[] = {1,2,3,4};
	int valueToBeDeleted = 3;
	Iterator it;
	void *temp;
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&values[0]);
	ASSERT(1 == result);
	insertNode(&tree, &values[0], &values[1]);
	insertNode(&tree, &values[0], &values[2]);
	result = insertNode(&tree, &values[0], &values[3]);

	result = deleteNode(&tree,&valueToBeDeleted);
	ASSERT(1==result);
}
