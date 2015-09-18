/*-------------------------------------------------------------------------
				Keyboard.h
--------------------------------------------------------------------------*/


#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <common.h>

//Initialises keyboard driver
void Keyboard_init(void);

//Sets the keyboard LED status
void Keyboard_setLeds(bool numLock, bool capsLock, bool scrollLock);

// Reads and returns a character stored inside circular QUEUE buffer
char Keyboard_getChar(void);

#endif
