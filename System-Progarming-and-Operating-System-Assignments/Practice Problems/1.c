#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<ctype.h>

void convert(char *str);
int main()
{
    int fd1[2];
    int fd2[2];
    char buff[10];
    pid_t x;
    pipe(fd1);
    pipe(fd2);
    x = fork();
    if (x == 0)
    {
        close(fd1[1]);
        read(fd1[0], buff, 5);
        printf("msg=%s\n", buff);
    }
    else
    {
        close(fd1[0]);
        write(fd1[1], "Hello", 6);
        close(fd1[1]);
    }

    return 0;
}
