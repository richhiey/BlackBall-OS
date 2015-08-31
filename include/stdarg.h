/*
Std arguments for ANSI C which helps capture variable length arguments in function calls
*/

ifndef _STDARG_H_
define _STDARG_H_

typedef char* va_list;

#define va_rounded_size(type) \
    (((sizeof (type) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))

#define va_start(ap, v) \
    ((void) (ap = (va_list) &v + va_rounded_size (v)))

#define va_arg(ap, type) \
    (ap += va_rounded_size (type), *((type *)(ap - va_rounded_size (type)))) 

#define va_end(ap) ((void) (ap = 0))

#endif
