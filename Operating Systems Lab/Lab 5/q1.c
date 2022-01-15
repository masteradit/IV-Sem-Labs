// 190911112
// Adit Luhadia
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    printf("190911112\nAdit Luhadia\n");
    pid_t pid;
    if (fork() == 0)
    {
        printf(" |-> Inside child \n");
        printf(" |-> Pid of child: %d \n", getpid());
        printf(" |-> PPid of child: %d \n", getppid());
        printf(" |-> Child Terminated \n\n");
        return 1;
    }
    else if (fork > 0)
    {
        printf("Inside parent \n");
        pid = wait(NULL);
        printf("Pid of Parent: %d \n", getpid());
        printf("PPid of Parent: %d \n", getppid());
        printf("Parent Terminated \n");
    }
    else
    {
        printf("Fork Failed");
    }
}
