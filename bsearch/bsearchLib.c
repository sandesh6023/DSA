#include "bsearchLib.h"
#include <stdio.h>

void* bsearch (const void* key,void* base, int num, int size,
	int (*compare)(const void*,const void*)){

	int length = num/2;
	if(compare(key,base + length*size)==0)
		return base + (length*size);

	if(0==length) return NULL;
	
	if(compare(key,base + (length*size))==-1){
		return bsearch(key,base,length,size,compare);
	}

	if(compare(key,base + (length*size)) ==1){
		base = base + length*size;
		return bsearch(key,base,num/2,size,compare);
	}
}