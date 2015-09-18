//Process mannager which provides various functions and typedefs to handle processes

#ifndef PROCESS_M_H
#define PROCESS_M_H

#include <module.h>
#include <X86/IDT.h>
#include <FileSystem/VFS.h>
#include <Utils/ArrayList.h>

#define KERNEL_PID 0   	//Process ID	

#define KERNEL_PROCESS 0		//Process tyoe
#define USER_PROCESS   1

#define PROCESS_CREATED     1
#define PROCESS_WAITING     2
#define PROCESS_RUNNING     3
#define PROCESS_BLOCKED     4
#define PROCESS_TERMINATED  5

typedef struct Process Process;

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

void  ProcessManager_switch(Regs* context); 		//Context switch method

void ProcessManager_killProcess(int exitCode);		//End current process and move on to next

Process* ProcessManager_spawnProcess(const char* binary);

coid ProcessManager_waitPID(Process* process);  	//Wait till current finishes

void ProcessManager_blockCurrentProcess(void);		//Blocking current from further execution, not necessary

#endif