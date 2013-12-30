#include "hash.h"

HashMap createHashMap(hashGenerator hash,compare cmp){
	HashMap hashInstance;
	int i;
	ArrayList *temp;
	ArrayList list = create(10);
	hashInstance.buckets =&list;
	hashInstance.cmp = cmp;
	hashInstance.hash = hash;
	for(i=0;i<10;i++){
		temp = (ArrayList*)hashInstance.buckets;
		temp->base[i] = createList();
	}
	return hashInstance; 
}

int put(HashMap *hashTable,void*key,void *data){
	int keyValue = hashTable->hash(*(int*)key);
	insertNode(  (List *)((ArrayList*)hashTable->buckets),0,data   );
	return 1;
	// hashTable->buckets
}