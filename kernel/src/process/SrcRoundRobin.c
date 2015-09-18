//Richhiey check this out
//Round robin hai

#include <Process/IncRoundRobin.h>
#include <Utils/linkedList.h>
#include <Memory/HeapMemory.h>
#include <debug.h>
#include <common.h>

PRIVATE LinkedList* processes;			//Private Data
PRIVATE Process* currentProcess;



PUBLIC void RoundRobin_addProcess(Process* process) {

    Debug_assert(process != NULL);								//Assertion methods to find out where the error is
    Debug_assert(process->status = PROCESS_CREATED);

    if(processes == NULL) { //Initialisation 

        processes = LinkedList_new();
        currentProcess = process;

    }

    process->status = PROCESS_WAITING;
    LinkedList_add(processes, process);

}

PUBLIC void RoundRobin_removeProcess(Process* process) {

    Debug_assert(process != NULL && processes != NULL);
    Debug_assert(process->pid != KERNEL_PID); //Kernal process should be left alone. Danger


    process->status = PROCESS_TERMINATED;
    LinkedList_remove(processes, process);

}

PUBLIC Process* RoundRobin_getNextProcess(void) {

    //Remove process from top of the queue
    Process* p = LinkedList_removeFromFront(processes);

    LinkedList_add(processes, p);
    currentProcess = p;
    return p;

}

PUBLIC Process* RoundRobin_getCurrentProcess(void) {

    return currentProcess;

}
