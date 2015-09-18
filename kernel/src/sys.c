//Provides important system functions

#include <Sys.h>
#include <Drivers/Console.h>
#include <Common.h>
#include <IO.h>
#include <Drivers/PS2Controller.h>

/*=======================================================
    DEFINE
=========================================================*/
#define SYS_C_RESET 0xFE

/*=======================================================
    FUNCTION
=========================================================*/
PUBLIC void Sys_restart(void)
{
    IO_outB(PS2_STATE, SYS_C_RESET);
}

/* Works in emulators such as qemu and bochs */
PUBLIC void Sys_powerOff(void)
{
    IO_outW(0xB004, 0x0 | 0x2000);
}

PUBLIC void Sys_panic(const char* str)
{
    Console_setColor(CONSOLE_RED);
    Console_printf("%s%s", "[PANIC] ", str);
    Sys_disableInterrupts(); /* We don't want CPU to wake up */
    Sys_haltCPU();
}