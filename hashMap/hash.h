#include "ArrayList.h"
#include "iterator.h"
#include "doublyLinkedLib.h"

typedef int (*compare)(void* a, void *b);
typedef int (*hashGenerator)(int value);

typedef struct {
	void *buckets;
	hashGenerator hash;
	compare cmp;
}HashMap;

HashMap createHashMap(hashGenerator hash,compare cmp);
int put(HashMap *hashTable,void*key,void *data);



Iterator getIterator(ArrayList* list);
Iterator getDoublyIterator(List* list);