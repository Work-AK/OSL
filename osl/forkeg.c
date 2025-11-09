#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void forkexample()
{
    if(fork()==0)
    {
        printf("This is child process. PID = %d", getpid());
    }
    else
    {
        printf("This is parent process. PID = %d", getppid());
    }
}

int main()
{
    forkexample();
    return 0;
}
