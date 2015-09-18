//scheduler

#include <Process/IncScheduler.h>
#include <debug.h>


#include <Process/IncRoundRobin.h>	// Or any other algo (FCFS)


PRIVATE bool isPreemptive;


PUBLIC void (*Scheduler_addProcess) (Process* process);
PUBLIC void (*Scheduler_removeProcess) (Process* process);
PUBLIC Process* (*Scheduler_getNextProcess) (void);
PUBLIC Process* (*Scheduler_getCurrentProcess) (void);



PUBLIC void Scheduler_init(void) {

    Scheduler_addProcess        = &RoundRobin_addProcess;
    Scheduler_removeProcess     = &RoundRobin_removeProcess;
    Scheduler_getNextProcess    = &RoundRobin_getNextProcess;
    Scheduler_getCurrentProcess = &RoundRobin_getCurrentProcess;

    isPreemptive = TRUE;
	
}

PUBLIC bool Scheduler_isPreemptive(void) {

    return isPreemptive;

}