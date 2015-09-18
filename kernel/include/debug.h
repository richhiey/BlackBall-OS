/*
TODO:
Add more debugging functions

To provide macros for printing debugging messages 
*/

#ifndef DEBUG_H
#define DEBUG_H

#include <Drivers/Console.h>
#include <Sys.h>

#define Debug_assert(C) if(!(C)) {Sys_panic("Assert failure!");}

#endif