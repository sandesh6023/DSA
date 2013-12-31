#include "include/ArrayList.h"
#include "include/doubleLL.h"

typedef int (*HashKeyGenerator)(void *value);
// typedef int (*compare)(void *a,void *b);

typedef struct {
	ArrayList buckets;
	HashKeyGenerator hashFunc;
	compare cmp;
}HashMap;

HashMap createHashmap(HashKeyGenerator hashFunc,compare cmp);
int put(HashMap *hash,void *key,void *value);
void *getSpecificRecord(HashMap *hash , void *key);
int deleteRecord(HashMap* hashtable,void* key);