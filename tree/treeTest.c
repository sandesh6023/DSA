#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int comparator(void* ID, void* data){
	return *(int*)ID == *(int*)data;
}


Tree tree;
int SUCCESS = 1;
void test_to_create_tree(){
	tree = createTree(comparator);
	ASSERT(NULL == tree.root);
	ASSERT(comparator == tree.cmp);
}

void test_to_insert_root_node(){
	int result;
	int arr[] = {1,2,3,4,5,6,7};
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&arr[0]);
	ASSERT(SUCCESS == result);
}

void test_to_insert_child_under_root_node(){
	int result;
	int arr[] = {1,2,3,4,5,6,7};
	tree = createTree(comparator);
	result = insertNode(&tree,NULL,&arr[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &arr[0], &arr[1]);
}