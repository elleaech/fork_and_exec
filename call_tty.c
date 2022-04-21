#include <syscall.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char *argv_list[] = {"tty", NULL};

    int rc = execvp("tty", argv_list);
    printf("rc=[%d]\n", rc);
}
