#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
void print_arr(int arr[100],int n)
{ 
   int i;
   printf("\n array elements are-->");
   for(i=0;i<n-1;i++)
   printf("%d\t",arr[i]);
    printf("%d\t]",arr[i]);
}
void bubblesort(int arr[100],int n)
{
   int pass,i,temp;
   for(pass=1;pass<n;pass++)
   {
   for(i=0;i<n-pass;i++)
   {
     if(arr[i]>arr[i+1])
     {
       temp=arr[i];
       arr[i]=arr[i+1];
      arr[i+1]=temp;
     }
   }
   }
}



void main()
{
  int arr[100],n;
  pid_t pid;
  printf("enter the size of array-->");
  scanf("%d",&n);
  printf("enter actual values:");
  for(int i=0;i<n;i++)
  {
     printf("\n enter the element[%d]-",i);
     scanf("%d",&arr[i]);
     
  }  
  print_arr(arr,n);
  printf("\n the sorted array by using bubble sort-->");
  bubblesort(arr,n);
  print_arr(arr,n);
  printf("\n forking the current process-->");
  pid=fork();
  if(pid==-1)
  printf("\n the child process was not create successfully:");
  else if(pid==0)
  {
  printf("\n child process was create successfully: ");
  char *buffer[n+1];
  int i;
  buffer[0]="./c222";
  for(i=1;i<n+1;i++)
  {
      buffer[i]=malloc(10);
      snprintf(buffer[i],10,"%d",arr[i-1]);
   }
    buffer[i]=NULL;
    execv("./c222",buffer);
    printf("\n\n child executed successfully\n");
  }
 else
 {
    printf("\n hello fron parent process-->");
    printf("------parent id waiting for child to complete-------");
    wait(NULL);
    printf("\n\n parent executes successfully\n\n");
 }
 }














