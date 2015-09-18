//Schduler, bryceleen ka hai
//Scheduler which can be made to use a certain scheduing algo (In this case Round Robin)

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Process/IncProcessManager.h>

extern void (*Scheduler_addProcess) (Process* process);		//Add process to scheduler

extern void (*Scheduler_removeProcess) (Process* process);		//Remove

extern Process* (*Scheduler_getNextProcess) (void);				//fetch next

extern Process* (*Scheduler_getCurrentProcess) (void);			//Return current

void Scheduler_init(void);										//initializing schudlar

bool Scheduler_isPreemptive(void);								//Check whether scheduler is preemptive

#endif