#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
   
    int p;
    p=fork();
   if(p>0)
   {
     printf(" parent process id is:%d\n",getpid());
   }
   else if (p==0)
   {
      printf("child process id is:%d\n",getpid());
      printf("parent process id is:%d\n",getppid());
      sleep(15);
      printf("child process id is:%d\n",getpid());
      printf("parent process id is:%d\n",getppid()); 
   } 
   else
   {
     printf("failed to terminate parent process");
   }
 }  
   
   
   
   
   
   
   
   
   
