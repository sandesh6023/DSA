#include "testUtils.h"
#include <stdio.h>
#include "osSchedulerLib.h"
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


Scheduler *queue;


void test_add_first_process_to_priorityQueue(){
        Status statusp1 = {0,0,0};
        Process p1 = {"p1",1000,statusp1,3,NULL};
        queue = create();
        ASSERT(1 == insertProcess(queue, &p1));
}

void test_sorts_processes_based_on_Process_priority(){
        Status statusp1 = {0,0,0};
        Process p1 = {"p1",1000,statusp1,3,NULL};
        Process p2 = {"p2",500,statusp1,1,NULL};
        queue = create();
        ASSERT(1 == insertProcess(queue, &p1));
        ASSERT(2 == insertProcess(queue, &p2));
}

void test_timeSlice_fails_when_there_is_no_process_in_Queue(){
        int result;
        queue = create();
        result = timeSlice(queue);
        ASSERT(0==result);
}

void test_timeSlice_executes_first_Process_for_10_seconds_and_changes_status(){
        Status statusp1 = {0,0,0};
        int result;

        Process *value;
        Process p1 = {"p1",40,statusp1,3,NULL};
        Process p2 = {"p2",10,statusp1,1,NULL};
        Process p3 = {"p3",10,statusp1,2,NULL};

        queue = create();
        ASSERT(1 == insertProcess(queue, &p1));
        ASSERT(2 == insertProcess(queue, &p2));       
        ASSERT(3 == insertProcess(queue, &p3));       

        result = timeSlice(queue);
        ASSERT(1==queue->head->processStatus.waiting);
        // value = queue->head;
        // printf("1st node %d\n",value->processPriority);
        // value = value->next;
        // printf("2nd node %d\n",value->processPriority);
}
