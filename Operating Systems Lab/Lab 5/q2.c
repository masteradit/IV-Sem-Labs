// 190911112
// Adit Luhadia
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv)
{
    int i, j;
    printf("190911112\nAdit Luhadia\n");
    if (fork() == 0)
    {
        char *temp;
        printf("Sorted Array: ");
        for (i = 1; i < argc; i++)
        {
            for (j = 1; j < argc - i; j++)
            {
                if (strcmp(argv[j], argv[j + 1]) > 0)
                {
                    temp = argv[j];
                    argv[j] = argv[j + 1];
                    argv[j + 1] = temp;
                }
            }
        }
        for (i = 1; i < argc; i++)
        {
            printf("%s ", argv[i]);
        }
        printf("\n");
        return 1;
    }
    if (fork() > 0)
    {
        wait(NULL);
        printf("Original Array: ");
        for (i = 1; i < argc; i++)
        {
            printf("%s ", argv[i]);
        }
        printf("\n");
        return 1;
    }
}
