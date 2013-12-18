#include "queueLib.h"

typedef struct {
	int priority;
	void *element;
} Element;


typedef char string[256];
void *dequeueRecord(Queue *queue);