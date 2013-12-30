#include "testUtils.h"
#include "hash.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};

int hashKeyGenerator(int id){
	return id%10;
}

int compareValues(void *a , void *b){
	return *(int *)a == *(int *)b;
}

void test_insert_element_into_hashMap(){
	int result;
	HashMap map = createHashMap(hashKeyGenerator, compareValues);
	result = put(&map,&prateek.id,&prateek);
	ASSERT(1==result);
}