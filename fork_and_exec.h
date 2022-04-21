#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#define ERROR -1
#define SUCCESS 0

#define UNINITIALIZED 999

typedef __pid_t pid;
