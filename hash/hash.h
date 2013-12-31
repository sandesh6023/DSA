#include "include/ArrayList.h"
#include "include/doubleLL.h"

typedef int (*HashKeyGenerator)(void *value,void *modulusKey);


typedef struct {
	ArrayList buckets;
	HashKeyGenerator hashFunc;
	compare cmp;
}HashMap;

typedef char String[256];

HashMap createHashmap(HashKeyGenerator hashFunc,compare cmp);
int put(HashMap *hash,void *key,void *value);
void *getSpecificRecord(HashMap *hash , void *key);
int deleteRecordFromHash(HashMap* hashtable,void* key);
Iterator getHashMapKeys(HashMap *hash);
void reHash(HashMap *hash);
void disposeHashMap(HashMap *map);