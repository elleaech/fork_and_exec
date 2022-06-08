#include "fork_and_exec.h"

void _printCurrentPID(char *task_name)
{
    pid current_task = getpid();

    if (NULL != task_name)
    {
        printf("%s PID: %d\n", task_name, current_task);
    }
    else
    {
        printf("PID: %d\n", current_task);
    }
}

int main()
{
    int32_t rc = SUCCESS;

    _printCurrentPID("PARRENT");

    // Fork process
    rc = fork();

    if (SUCCESS == rc)
    {
        char *argv_list[] = {"sleep", "4", NULL};

        _printCurrentPID("FORK");

        // Replace the current process image (child) with new one
        rc = execv("/bin/sleep", argv_list);
    }
    else if (ERROR == rc)
    {
        printf("FAILED TO FORK PROCESS\n");
    }
    // Wait for child process to finish
    else
    {
        waitpid(rc, NULL, 0);
    }

    printf("rc=[%d]\n", rc);
    return rc;
}
