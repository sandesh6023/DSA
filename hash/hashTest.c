#include "testUtils.h"
#include "hash.h"
#include "stdio.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char String[256];

int hashGenerator(void *value){
	int i;
	int hashValue = 0;
	char *string = (char*)value;
	int length = strlen((char*)value);
	for(i=0;i<length;i++)
		hashValue += string[i];
	return hashValue%10;
}

int compareKeys(void *first,void *second){
	return strcmp( (char*)first,(char*)second )==0;
}
typedef struct {
	int id;
	char* name;
}Intern;

Intern intern1 = {123,"prateek"};
Intern intern2 = {122,"manish"};

void test_create_HashMap_and_insertValue(){
	int result;
	char *key = "san";
	HashMap hash = createHashmap(hashGenerator,compareKeys);
	result = put(&hash,&key,&intern1);
}

void test_InsertValues_to_hashMap_and_access_values(){
	int result;
	void *expectedValue;
	String keys[] = {"aa","bb", "cc"};
	String values[] = {"san","man","dan"};
	HashMap hash = createHashmap(hashGenerator,compareKeys);
	put(&hash,&keys[0],&values[0]);
	put(&hash,&keys[1],&values[1]);
	result = put(&hash,&keys[2],&values[2]);
	ASSERT(1==result);
	expectedValue = getSpecificRecord(&hash,&keys[1]);
	ASSERT(0==strcmp(expectedValue,values[1]));
}

