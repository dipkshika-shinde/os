#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void bubblesort(int x[],int n)
{
   int pass,i,temp;
   for(pass=1;pass<n;pass++)
   {
   for(i=0;i<n-pass;i++)
   {
     if(x[i]>x[i+1])
     {
       temp=x[i];
       x[i]=x[i+1];
       x[i+1]=temp;
     }
   }
   }
}

void insertionsort(int x[],int n)
{
  int k,i,key;
  for(k=1;k<n;k++)
  {
  key=x[k];
  for(i=k-1;x[i]>key && i>=0;i--)
  {
  x[i+1]=x[i];
  }
  x[i+1]=key;
  }
}

void fork1()
{
     int x[10],n,i,status;
     printf("Enter the no of values in array:");
     scanf("%d",&n);
     printf("\n Enter the array element");
     for(i=0;i<n;i++)
     {
       scanf("%d",&x[i]);
       int pid=fork();
       if(pid==0)
       {
       sleep(10);
       printf("\n child process\n");
       printf("child process id =%d\n",getpid());
        
        insertionsort(x,n);
        printf("\n elements sorted using insertion sort:");
        printf("\n");
        for(i=0;i<n;i++)
        printf("%d",x[i]);
        printf("\n");
        printf("\n parent process id=%d\n",getpid());
       }
       else
       {
       printf("\n parent process\n");
       printf("\n parent process id=%d\n",getpid());
       bubblesort(x,n);
       printf("elements sorted udsing bubble sort:");
       printf("\n");
       for(i=0;i<n;i++)
       printf("%d",x[i]);
       printf("\n\n\n");
       
     }
}
}

int main()
{
   fork1();
   {
   return 0;
   }
}
