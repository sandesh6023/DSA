#include "ArrayList.h"

typedef int (*compare)(void* a, void *b);
typedef int (*hashGenerator)(int value);

typedef struct {
	void *buckets;
	hashGenerator hash;
	compare cmp;
}HashMap;

HashMap createHashMap(hashGenerator hash,compare cmp);
