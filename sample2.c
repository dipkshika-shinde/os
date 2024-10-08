#include<stdio.h>
#include<sys/types.h>
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
  }
  void parentprocess()
  {
     printf("I am parent process\n");
  }
