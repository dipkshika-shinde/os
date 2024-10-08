#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
 int main()
{
   int p,n;
   printf("press DEL to stop process\n");
   p=fork();
   for(;;)
   {
      if(p==0)
      {
        n=nice(-7);
        printf("child gets higher CPU priority %d\n",n);
        sleep(1);
      }
      else
      {
       n=nice(5);
       printf("parent gets lower CPU priority %d\n",n);
        sleep(1);
      }
   }
}
