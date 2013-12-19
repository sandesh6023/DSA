#include "osSchedulerLib.h"
#include <stdlib.h>
#include <string.h>


Scheduler* create(){
    Scheduler *processQueue = calloc(sizeof(Scheduler),1);
    return processQueue;
}

int insertAtStart(Scheduler *processQueue, Process *process){
        if(processQueue->head == NULL)
                process->next = NULL;
        process->next = processQueue->head;
        processQueue->head = process;
        processQueue->length++;
                return processQueue->length;        
}

int insertProcessInBetween(Scheduler *processQueue,Process *previous,Process *process ,Process *next){
    previous->next = process;
    process->next = next;
    processQueue->length +=1;
    return processQueue->length;
}

int insertProcess(Scheduler *processQueue, Process *process){
    Process *previous,*next,*temp;
    temp = processQueue->head;
    if(processQueue->length == 0)                
        return insertAtStart(processQueue, process);
    if(process->processPriority < temp->processPriority)
        return insertAtStart(processQueue, process);

    while(temp->next!=NULL){
        // temp = temp->next;
        previous=temp;
        next = temp->next;
        if(process->processPriority < next->processPriority)
            return insertProcessInBetween(processQueue ,previous, process ,next);
        temp = temp->next;
    }
    temp->next = process;
    process->next = NULL;
    processQueue->length +=1;
    return processQueue->length;
}

int timeSlice(Scheduler *processes){
    Process *temp;
    Status *stat;
    if(processes->head == NULL)
        return 0;
    temp = processes->head;
    temp->processTime -=10;
    temp->processStatus.running=0;
    temp->processStatus.waiting=1;
    temp->processStatus.completed=0;

    return 1;
}