//VGA text mode based buffer

#include <Drivers/VGA.h>

/*=======================================================
    PRIVATE DATA
=========================================================*/
PRIVATE Module vga;

/*=======================================================
    PUBLIC DATA
=========================================================*/
PUBLIC char*  vgaRam;
PUBLIC u8int  vgaHeight;
PUBLIC u8int  vgaWidth;

/*=======================================================
    FUNCTION
=========================================================*/
PRIVATE void VGA_init(void)
{
    vgaRam    = (char*) 0xB8000;
    vgaWidth  = 80;
    vgaHeight = 25;
}

PUBLIC Module* VGA_getModule(void)
{
    vga.moduleName = "VGA Driver";
    vga.moduleID = MODULE_VGA;
    vga.init = &VGA_init;

    return &vga;
}