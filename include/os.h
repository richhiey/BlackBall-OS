/*
Header file to define the basic system calls
*/

#ifndef BLACKBALL_H
#define BLACKBALL_H

//System call identifiers
#define SYSCALL_PUTS        1
#define SYSCALL_PUTC        2
#define SYSCALL_EXIT        3
#define SYSCALL_POWEROFF    4
#define SYSCALL_FCHDIR      5
#define SYSCALL_FPARENT     6
#define SYSCALL_GETCWD      7
#define SYSCALL_READDIR     8
#define SYSCALL_FGETCWD     9
#define SYSCALL_RESTART     10
#define SYSCALL_CLS         11
#define SYSCALL_GETCH       12
#define SYSCALL_OPEN        13
#define SYSCALL_CLOSE       14
#define SYSCALL_READ        15
#define SYSCALL_WRITE       16
#define SYSCALL_WAITPID     17
#define SYSCALL_SBRK        18
#define SYSCALL_FINDDIR     19
#define SYSCALL_CHDIR       20
#define SYSCALL_SETCOLOR    21
#define SYSCALL_SPAWN       22
#define SYSCALL_MKDIR	    23

#define FILE int

//Function definitions
void puts(const char* str);
void putc(char c);
void exit(int exitCode);
int spawn(const char* binary);
FILE* readdir(FILE* fd, int index);
FILE* finddir(FILE* fs, const char* childname);
FILE* fchdir(FILE* fd);
FILE* chdir(const char* dir);
FILE* fparent(FILE* fd);
FILE* fgetcwd(void);
char* getcwd(char* buf);
char getch(void);
void cls(void);
void restart(void);
void poweroff(void);
FILE* open(const char* path, const char* mode);
void close(FILE* file);
unsigned int read(FILE* file, unsigned int offset, unsigned int count, char* buffer);
unsigned int write(FILE* file, unsigned int offset, unsigned int count, const char* buffer);
FILE* mkdir(const char* pathname);
void* sbrk(int size);
void color(unsigned int attr);
void waitpid(int pid);
#endif
