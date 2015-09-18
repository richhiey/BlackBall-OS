//Locking unlocking process iusing mutex


#ifndef MUTEX_H
#define MUTEX_H

#include <Sys.h>

static inline void Mutex_lock() {

    Sys_disableInterrupts();

}

static inline void Mutex_unlock() {

    Sys_enableInterrupts();

}

#endif