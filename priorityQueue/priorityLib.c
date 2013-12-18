#include "priorityLib.h"
#include <stdlib.h>

int compareStructure ( const void* a,  const void* b){
	Element *ele1 = (Element*)a;
	Element *ele2 = (Element*)b;
	return ele1->priority - ele2->priority;
}

void *dequeueRecord(Queue *queue){
	qsort(queue->elements,(queue->rear+1),sizeof(Element),compareStructure);
	return dequeue(queue);
}