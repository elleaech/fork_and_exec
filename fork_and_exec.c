#include "fork_and_exec.h"

void aechGetPID(pid *process)
{
    if (NULL != process)
    {
        *process = getpid();
    }
}

int main()
{
    int32_t rc = SUCCESS;
    pid current_task = UNINITIALIZED;

    aechGetPID(&current_task);
    printf("PARRENT PID: %d\n", current_task);

    rc = fork();
    // printf("rc=[%d]\n", rc);

    if (SUCCESS == rc)
    {
        aechGetPID(&current_task);
        printf("FORK PID: %d\n", current_task);

        char *argv_list[] = {"call_tty", NULL};

        rc = execv("./call_tty", argv_list);
        printf("rc=[%d]\n", rc);
    }
    else if (ERROR == rc)
    {
        printf("FAILED TO FORK PROCESS\n");
    }

    return rc;
}

/*
OUTPUT
-------------

elleaech@sourcerer:/media/elleaech/storage/bin/C/fork_and_exec$ gcc -o fork_and_exec.elf fork_and_exec.c && ./fork_and_exec.elf
PARRENT PID: 229304
FORK PID: 229305

elleaech@sourcerer:/media/elleaech/storage/bin/C/fork_and_exec$ ps -ef | grep "sleep 1000"
elleaech  229305    1370  0 16:06 pts/3    00:00:00 sleep 1000
elleaech  229587  177970  0 16:07 pts/3    00:00:00 grep --color=auto sleep 1000

*/
