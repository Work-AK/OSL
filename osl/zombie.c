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
    if(PID == 0)
    {
        printf("This is child process. PID = %d", getpid());
    }
    else
    {
        printf("This is parent process. PID = %d", getpid());
        sleep(10);
        printf("*********Parent\n");
        system("ps -axj | tail");
    }
    return 0;
}
