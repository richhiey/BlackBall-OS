//Provides important system functions

#include <sys.h>
#include <Drivers/console.h>
#include <common.h>
#include <IO.h>

/*=======================================================
    DEFINE
=========================================================*/
#define SYS_C_RESET 0xFE

/*=======================================================
    FUNCTION
=========================================================*/

/* Works in emulators such as qemu and bochs */
PUBLIC void Sys_powerOff(void)
{
    IO_outW(0xB004, 0x0 | 0x2000);
}

PUBLIC void Sys_panic(const char* str)
{
    Console_setColor(CONSOLE_RED);
    Console_printf("%s%s", "[PANIC] ", str);
    Sys_disableInterrupts();
    Sys_haltCPU();
}