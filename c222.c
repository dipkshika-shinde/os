#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
void print_arr(int arr[100],int n)
{ 
   int i;
   printf("\n array elements are-->");
   for(i=0;i<n-1;i++)
   printf("%d",arr[i]);
   printf("%d]",arr[i]);
} 

int binarysearch(int arr[100],int n,int key)
{
  int mid,top,bottom;
  top=0;
  bottom=n-1;
  mid=(top+bottom)/2;
  while(top<=bottom)
  {
    if(arr[mid]<key)
    top=mid+1;
    else if(arr[mid]==key)
    {
    printf("\n element was found in array-->%d\n",mid);
    break;
  }
  else
  bottom=mid-1;
  mid=(top+bottom)/2;
}
if(top>bottom)
printf("\n element was not found on array-->\n");
}


void main(int argc,char *argv[],char *envp)
{
   int arr[argc-1],key;
   for(int i=1;i<argc;i++)
   arr[i-1]=atoi(argv[i]);
   print_arr(arr,argc-1);
   printf("enter the value to be searched--> ");
   scanf("%d",&key);
   binarysearch(arr,argc-1,key);
}

