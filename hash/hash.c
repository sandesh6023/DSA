#include "hash.h"
#include "stdlib.h"
typedef struct {
	void *key;
	void *record;
}Record;

HashMap createHashmap(HashKeyGenerator hashFunc,compare cmp){
	HashMap hash;
	int i;
	hash.buckets = createList(10);
	hash.cmp = cmp;
	hash.hashFunc = hashFunc;
	for(i=0;i<10;i++){
		hash.buckets.base[i] = create();
	}
	return hash;
}
Record *getRecord(void *key,void *value){
	Record *recordInstance = malloc(sizeof(Record));
	recordInstance->key = key;
	recordInstance->record = value;
	return recordInstance;
}

int put(HashMap *hash,void *key,void *value){
	List *currentBucket;
	int bucketValue = hash->hashFunc(key);
	Record *record1 = getRecord(key,value);
	currentBucket = hash->buckets.base[bucketValue];
	insert(currentBucket,0,record1);
	return 1;
}

void *getSpecificRecord(HashMap *hash , void *key){
	Iterator it;
	List *currentBucket;
	Record *element;
	int bucketValue = hash->hashFunc(key);
	currentBucket = hash->buckets.base[bucketValue];

	it = getIterator(currentBucket);
	while(it.hasNext(&it)){
		element = it.next(&it);
		if(hash->cmp(element->key,key))
			return element->record;
	}
	return NULL;
}