#include "testUtils.h"
#include "hash.h"
#include <stdio.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

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

void test_create_HashMap_and_insertValue(){
	HashMap hashtable = createHashmap(hashGenerator,compareKeys);
	char* key = "key";
    char* value = "Value";
    int result = put(&hashtable, key, value);
    ASSERT(result == 1);
    disposeHashMap(&hashtable);
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
    disposeHashMap(&hash);

}

void test_to_get_a_record_from_hashtable_when_there_are_more_elements(){
    void* answer;
    String keys[] = {"aaa","bbb"};
    String values[] = {"lee","adam","jack"};
	
	HashMap hashtable = createHashmap(hashGenerator,compareKeys);

    int result = put(&hashtable, &keys[0], &values[0]);
    ASSERT(result == 1);
    result = put(&hashtable,&keys[1],&values[1]);
    ASSERT(result == 1);
    answer = getSpecificRecord(&hashtable, &keys[1]);
    disposeHashMap(&hashtable);

}

void test_should_Update_the_existing_record_when_user_gives_record_with_sameKey(){
    void* answer;
    String keys[] = {"aaa","bbb"};
    String values[] = {"lee","adam","jack"};
	
	HashMap hashtable = createHashmap(hashGenerator,compareKeys);

    int result = put(&hashtable, &keys[0], &values[0]);
    ASSERT(result == 1);
    result = put(&hashtable,&keys[1],&values[1]);
    ASSERT(result == 1);
    answer = getSpecificRecord(&hashtable, &keys[1]);
    ASSERT(0 == strcmp((char*)answer, values[1]));
    result = put(&hashtable,&keys[1],&values[2]);
    ASSERT(result == 1);
    answer = getSpecificRecord(&hashtable, &keys[1]);

    ASSERT(0 == strcmp((char*)answer, values[2]));
    disposeHashMap(&hashtable);

}

void test_should_delete_record_from_hashMap(){
    void* answer;

	HashMap hashtable = createHashmap(hashGenerator,compareKeys);

    String keys[] = {"aa"};
    String values[] = {"lee"};
    int result = put(&hashtable, &keys[0], &values[0]);
    ASSERT(result == 1);
    answer = getSpecificRecord(&hashtable, &keys[0]);
    ASSERT(0 == strcmp((char*)answer, values[0]));
    result = deleteRecordFromHash(&hashtable,&keys[0]);
    answer = getSpecificRecord(&hashtable, &keys[0]);
    ASSERT(answer == NULL);
    disposeHashMap(&hashtable);

}

void test_should_get_keys_from_hashTable(){
	void *answer;
	Iterator doublyIt;
    String keys[] = {"aaa","bbb","ccc"};
    String values[] = {"lee","adam","jack"};
    int result;
		
	HashMap hashtable = createHashmap(hashGenerator,compareKeys);

    put(&hashtable, &keys[0], &values[0]);
    put(&hashtable,&keys[1],&values[1]);
	put(&hashtable,&keys[2],&values[2]);
    doublyIt = getHashMapKeys(&hashtable);

    result = doublyIt.hasNext(&doublyIt);
    ASSERT(1==result);
    answer = doublyIt.next(&doublyIt);

    ASSERT(0 == strcmp((char*)answer, keys[2]));
    answer = doublyIt.next(&doublyIt);
    ASSERT(0 == strcmp((char*)answer, keys[1]));
    answer = doublyIt.next(&doublyIt);
    ASSERT(0 == strcmp((char*)answer, keys[0]));
    disposeHashMap(&hashtable);

}