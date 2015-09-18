//Inckude this for roundrobin


#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <Process/ProcessManager.h>


void RoundRobin_addProcess(Process* process);		//Add Process


void RoundRobin_removeProcess(Process* process);	//Remove process

Process* RoundRobin_getNextProcess(void);			//Get Next process


Process* RoundRobin_getCurrentProcess(void);		//Get current process

#endif