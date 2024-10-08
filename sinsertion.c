#include<stdio.h>
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

void main()
 {
   void insertionsort();
   int x[10],n,i;
   printf("How many values:");
   scanf("%d",&n);
   printf("Enter actual number:");
   for(i=0;i<n;i++)
   {
     scanf("%d",&x[i]);
   }
   insertionsort(x,n);
   printf("The sorted elements are:");
   for(i=0;i<n;i++)
   {
     printf("%d\t",x[i]);
   }
 }
 
