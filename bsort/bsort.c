#include "bsort.h"
#include <memory.h>
#include <stdlib.h>
void bsort(void* base, size_t numberOfElements, size_t elementSize,
			compare comp) {
    int i, j;
    void* temp = calloc(1, elementSize);
    void* successiveElement = calloc(1,elementSize);
    void* previousElement = calloc(1,elementSize);

    void* elementToCompare;
    int comparisonResult;
    
    for (i = 0; i < numberOfElements; i++) {
    	for(j=1;j<numberOfElements;j++){
    		comparisonResult = comp(base + (j*elementSize),base +((j-1)*elementSize));
	    		if(comparisonResult == 1){
	    			memcpy(temp,base + (j*elementSize),elementSize);
	    			memcpy(base + (j*elementSize),base +((j-1)*elementSize),elementSize);
	    			memcpy(base +((j-1)*elementSize),temp,elementSize);
	    	}
    	}
    }
    
    free(temp);
}
