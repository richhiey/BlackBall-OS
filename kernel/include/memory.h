/**
| Copyright(C) 2012 Ali Ersenal
| License: WTFPL v2
| URL: http://sam.zoy.org/wtfpl/COPYING
|
|--------------------------------------------------------------------------
| Memory.h
|--------------------------------------------------------------------------
|
| DESCRIPTION:  Provides functions which modify memory.
|
| AUTHOR:       Ali Ersenal, aliersenal@gmail.com
\------------------------------------------------------------------------*/


#ifndef MEMORY_H
#define MEMORY_H

#include <Common.h>
#include <Debug.h>

//Set a certain block of memory with a certain value
static inline void Memory_set(void* ptrToMem, char valueToSet, u32int length)
{
    Debug_assert(ptrToMem != NULL);

    char* ptr = (char*) ptrToMem;

    for(u32int i = 0; i < length; i++)
	{
        *ptr = valueToSet;
        ptr++;
    }
}

//Copies a block of memory from source to destination
static inline void Memory_copy(void* destination,const void* source, u32int sourceLength)
{
    Debug_assert(destination != NULL);
    Debug_assert(source != NULL);

    char* dest = (char*) destination;
    char* src  = (char*) source;

    for(u32int i = 0; i < sourceLength; i++)
	{
        *(dest + i) = *(src + i);
    }
}

#endif
