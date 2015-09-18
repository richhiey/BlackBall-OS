//Console driver

#ifndef CONSOLE_H
#define CONSOLE_H

#include <common.h>
#include <module.h>

/*=======================================================
    DEFINE
=========================================================*/

// Console colors
#define CONSOLE_RED   0x0C //light-red
#define CONSOLE_BLUE    0x09 //light-blue
#define CONSOLE_YELLOW    0x0E //yellow
#define CONSOLE_NORMAL  0x07 //grey

/*=======================================================
    FUNCTION
=========================================================*/

// Constructs a string using the specified template and variable arguments and then prints it.
void Console_printf(const char* template, ...);

//Printing char on console
void Console_printChar(u8int c);

//Printing a string on the console
void Console_printString(const char* str);

//Clears the console screen
void Console_clearScreen(void);

//Sets the color for the console
void Console_setColor(u8int colorAttribute);

//Used to initialize or use the console module
Module* Console_getModule(void);
#endif
