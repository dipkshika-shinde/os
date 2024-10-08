#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    int pid;
    pid=fork();
    if(pid==0)
    {
    char *args[]={"./ass1",NULL};
    execvp(args[0],args);
    }
    else
    {
    printf("i am parent process------\n");
    }
    return 0;
}
