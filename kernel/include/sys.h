/*
Provides important system functions
*/

#ifndef SYS_H
#define SYS_H

//Restarts the machine
void Sys_restart(void);

//Shut down the machine
void Sys_powerOff(void);

//Throws a panic message and halts the CPU
void Sys_panic(const char* str);

//Makes the system idle. Halts the CPU
static inline void Sys_haltCPU(void)
{
    /* NOTE: "memory" clobber prevents gcc optimisation(which we don't want) */
    asm volatile("hlt" ::: "memory");
}

//Enable/Disable interrupts
static inline void Sys_enableInterrupts(void)
{
    asm volatile("sti" ::: "memory");
}

static inline void Sys_disableInterrupts(void)
{
    asm volatile("cli" ::: "memory");
}

#endif
