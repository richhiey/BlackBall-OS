//Process mannager which provides various functions and typedefs to handle processes

#ifndef PROCESS_M_H
#define PROCESS_M_H

#include <module.h>
//#include <X86/IDT.h>				TODO
//#include <FileSystem/VFS.h>		TODO
//#include <Utils/ArrayList.h>		TODO

#define KERNEL_PID 0   	//Process ID	

#define KERNEL_PROCESS 0		//Process tyoe
#define USER_PROCESS   1

//Process states
#define PROCESS_CREATED     1
#define PROCESS_WAITING     2
#define PROCESS_RUNNING     3
#define PROCESS_BLOCKED     4
#define PROCESS_TERMINATED  5

//Structure containing information which makes up a process
struct Process
{
    u32int pid;
    u8int  status;
    char   name[64];
    void*  userHeapTop;
    void*  kernelStack;
    void*  kernelStackBase;
    void*  userStack;
    void*  userStackBase;
    void*  pageDir;

    VFSNode* workingDirectory;
    ArrayList* fileNodes;
};

typedef struct Process Process;

//Important functions for process management
void  ProcessManager_switch(Regs* context); 		//Context switch method

void ProcessManager_killProcess(int exitCode);		//End current process and move on to next

Process* ProcessManager_spawnProcess(const char* binary);	//Spawns a child process

coid ProcessManager_waitPID(Process* process);  	//Wait till current finishes

void ProcessManager_blockCurrentProcess(void);		//Blocking current from further execution, not necessary

#endif