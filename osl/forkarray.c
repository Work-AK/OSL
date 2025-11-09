#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int arr_child[] = {1, 2 ,3, 4, 5, 6, 7, 8};
int arr_parent[] = {8, 7, 6, 5, 4, 3, 2, 1};
int n = 8;

void bubblesort_child(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] < arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array in decending order by child process: \n");
}

void bubblesort_parent(int arr[], int n)
{
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j + 1] < arr[j])
            temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }
    printf("Array in Ascending order by parent process: \n");
}

void display(int arr[])
{
    printf("Array:");
    for(int i = 0; i < n; i++)
    {
        printf(" %2d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    pid_t PID;
    PID = fork();
    if(PID < 0)
    {
        printf("Error creating new process");
    }
    if(PID == 0)
    {
        printf("\nThis is child process. PID = %d\n", getpid());
        bubblesort_child(arr_child, n);
        display(arr_child);
    }
    else
    {
        printf("\nThis is Parent process. PID = %d\n", getpid());
        bubblesort_parent(arr_parent, n);
        display(arr_parent);
    }
    return 0;
}
