#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t x;

    x = fork();
    if(x == 0)
    {
        printf("Child process\n");
        execl("add", "add", "5", "6", (char*)0);
        printf("End\n");
    }
    else
    {
        printf("Parent\n");
    }
    return 0;
}