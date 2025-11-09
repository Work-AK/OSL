#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t PID;
    PID = fork();
    if(PID < 0)
    {
        printf("Process creation failed");
    }
    else if(PID == 0)
    {
        sleep(5);
        printf("\nThis is child process. PID = %d", getpid());
        printf("\nThis is child's parent process PID = %d", getppid());
        exit(0);
    }
    else
    {
        printf("\nThis is parent process. PID = %d", getpid());
        exit(0);

    }
    return 0;
}
