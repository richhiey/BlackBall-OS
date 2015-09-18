/*
Provides common definitions and typedefs
*/

#ifndef COMMON_H
#define COMMON_H

/* Get the number of elements in an array */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

/* Null type */
#define NULL   ((void *)0)

/** 32 bit X86 types */
typedef unsigned long long  u64int;
typedef unsigned int        u32int;
typedef unsigned short      u16int;
typedef unsigned char       u8int;

typedef unsigned int size_t;
typedef signed int   ptrdiff_t;

/** Boolean type **/
typedef unsigned char bool;
#define TRUE  1
#define FALSE 0

#endif
