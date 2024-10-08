#include<stdio.h>
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
   
void main()
 {
   void bubblesort();
   int x[10],n,i;
   printf("How many values:");
   scanf("%d",&n);
   printf("Enter actual number:");
   for(i=0;i<n;i++)
   {
     scanf("%d",&x[i]);
   }
   bubblesort(x,n);
   printf("The sorted elements are:");
   for(i=0;i<n;i++)
   {
     printf("%d\t",x[i]);
   }
 }
 
 
 
 
 
 
 
                                                                                                                                                                                                                                                                                                                      
