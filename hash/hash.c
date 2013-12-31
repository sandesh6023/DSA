#include "hash.h"
#include "stdlib.h"

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

Record* checkForExistingRecord(List* currentBucket, HashMap* hashtable,void* key){
    Iterator it;
    Record* elem;
    it = getIterator(currentBucket);
    while(it.hasNext(&it)){
            elem = it.next(&it);
            if(hashtable->cmp(elem->key,key))
                    return elem;
    }
    return NULL;
}
int put(HashMap *hash,void *key,void *value){
  	Record *record;
    int bucketNo;
    Record* temp;
    List* currentBucket;
    record = getRecord(key,value);
    bucketNo = hash->hashFunc(key);
    currentBucket = (List*)(hash->buckets.base[bucketNo]);
    temp = checkForExistingRecord(currentBucket,hash,key);
    if(temp == NULL)
            insert(currentBucket, 0, record);
    else
            temp->record = value;
    return 1;
}

void *getSpecificRecord(HashMap *hash , void *key){
  Iterator it;
    int bucketNo;
    Record* elem;
    List* currentBucket;
    bucketNo = hash->hashFunc(key);
    currentBucket = ((List*)(hash->buckets.base[bucketNo]));
    it = getIterator(currentBucket);
    while(it.hasNext(&it)){
            elem = it.next(&it);
            if(hash->cmp(elem->key,key))
                    return elem->record;
    }
    return NULL;
}

int deleteRecordFromHash(HashMap* hashtable, void* key){
    Iterator it;
    int bucketNo,index=0;
    Record* elem;
    List* currentBucket;
    bucketNo = hashtable->hashFunc(key);
    currentBucket = ((List*)(hashtable->buckets.base[bucketNo]));
    it = getIterator(currentBucket);
    while(it.hasNext(&it)){
        elem = it.next(&it);
        if(hashtable->cmp(elem->key,key))
                break;
        index++;
    }
    removeNode(currentBucket, index);
    return 1;
}

Iterator getHashMapKeys(HashMap *map){
    Iterator it1;
    Iterator it2;
    Iterator result;
    Record *data;
    List *list = create();
    it1 = getIteratorOfArrayList(&map->buckets);
    while(it1.hasNext(&it1)){
        it2 = getIterator(it1.next(&it1));
        while(it2.hasNext(&it2)){
           data = it2.next(&it2);
           insert(list, 0, data->key);
        }
    }
    result = getIterator(list);
    return result;
}