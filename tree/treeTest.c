#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>

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

void test_to_insert_child_under_root_node(){
	int result;
	int arr[] = {1,2,3};
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&arr[0]);
	ASSERT(1 == result);
	result = insertNode(&tree, &arr[0], &arr[1]);
	ASSERT(1== result);
	result = insertNode(&tree, &arr[0], &arr[2]);
	ASSERT(1== result);

}

void test_insert_child_node_under_subroot_node(){
	int result;
	int arr[] = {1,2,3};
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&arr[0]);
	ASSERT(1 == result);
	// result = insertNode(&tree, &arr[0], &arr[1]);

	ASSERT(1== result);
}