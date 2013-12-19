typedef struct{
        int running;
        int waiting;
        int completed;
} Status;

typedef struct process{
        char processName[256];
        int processTime;
        Status processStatus;
        int processPriority;
        struct process *next;
} Process;

typedef struct{
        Process *head;
        int length;
} Scheduler;

Scheduler* create();
int timeSlice(Scheduler *processes);
int insertProcess(Scheduler *queue, Process *process);
Process* removeProcess(Scheduler *queue);

