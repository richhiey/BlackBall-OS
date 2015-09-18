/*
VGA text mode driver
*/

#ifndef VGA_H
#define VGA_H

#include <common.h>
#include <IO.h>
#include <module.h>

/*=======================================================
    DEFINE
=========================================================*/
#define CRTC_SELECT 0x3D4
#define CRTC_MODIFY 0x3D5

/*=======================================================
    PUBLIC DATA
=========================================================*/
extern char*  vgaRam;
extern u8int  vgaHeight;
extern u8int  vgaWidth;

/*=======================================================
    FUNCTION
=========================================================*/

//Get VGA module
Module* VGA_getModule(void);

//Puts character in text buffer
static inline void VGA_put(u16int index, u16int data)
{
    *((u16int*) vgaRam + index) = data;
}

//Moves the textmode cursor to specified offset
static inline void VGA_moveCursor(u16int cursorLoc)
{
    /* Select register 14 */
    IO_outB(CRTC_SELECT, 14);
    /* Modify register 14 */
    IO_outB(CRTC_MODIFY, cursorLoc >> 8); /* Send low byte */

    /* Select register 15 */
    IO_outB(CRTC_SELECT, 15);
    /* Modify register 15 */
    IO_outB(CRTC_MODIFY, cursorLoc); /* Send high byte */
}

#endif