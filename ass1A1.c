#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void parentprocess();
void childprocess();
int main()
{
    pid_t p;
    p=fork();
    if(p==0)
    childprocess();
    else
    parentprocess();
    return 0;
}

  void childprocess()
  {
   
    printf("I am child process\n");
    getpid();
    printf("The child process id is:%d\n",getpid());
  }
  void parentprocess()
  {
     printf("I am parent process\n");
     getpid();
     printf("The parent process id is:%d\n",getpid());
  }
