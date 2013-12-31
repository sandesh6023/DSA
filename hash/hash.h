#include "include/ArrayList.h"
#include "include/doubleLL.h"

typedef int (*HashKeyGenerator)(void *value);
typedef char String[256];
typedef struct {
	void *key;
	void *record;
}Record;


// typedef int (*compare)(void *a,void *b);

typedef struct {
	ArrayList buckets;
	HashKeyGenerator hashFunc;
	compare cmp;
}HashMap;

HashMap createHashmap(HashKeyGenerator hashFunc,compare cmp);
int put(HashMap *hash,void *key,void *value);
void *getSpecificRecord(HashMap *hash , void *key);
int deleteRecordFromHash(HashMap* hashtable,void* key);
Iterator getHashMapKeys(HashMap *hash);