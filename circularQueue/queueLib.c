#include "queueLib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Queue* create(int typeSize, int noOfElements){
	Queue *queue = malloc(sizeof(Queue));
	queue->elements = calloc(noOfElements,typeSize);
	queue->noOfElements = noOfElements;
	queue->elementSize = typeSize;
	queue->front = -1;
	queue->rear = -1;
	return queue;	
}

int enqueue(Queue *queue, void *inputElement){
	if((queue->rear+1) % queue->noOfElements == queue->front) 
		return 0;

	queue->rear = queue->rear + 1;
	memcpy(queue->elements+(queue->rear*queue->elementSize),inputElement,queue->elementSize);
	
	if(queue->front==-1) queue->front = 0;
	return 1;
}


void* dequeue(Queue *queue){
	if(queue->front == -1 || (queue->front)%queue->noOfElements == queue->rear+1)
	return NULL;

	queue->front = queue->front + 1;
	if((queue->front)%queue->noOfElements==0){
		queue->front=-1;
		return NULL;
	}
	return queue->elements + ((queue->front % queue->noOfElements) *queue->elementSize); 
}