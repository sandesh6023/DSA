#include "hash.h"


HashMap createHashMap(hashGenerator hash,compare cmp){
	HashMap hashInstance;
	ArrayList list = create(10);
	hashInstance.buckets =&list;
	hashInstance.cmp = cmp;
	hashInstance.hash = hash;
	return hashInstance; 
}
