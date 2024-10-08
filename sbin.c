#include<stdio.h>
int binsearch(int a[],int n,int key)
{
  int mid,top,bottom;
  top=0;
  bottom=n-1;
  while(top<bottom)
  {
    mid=(top+bottom)/2;
    if(a[mid]==key)
    return mid;
    else
    if(key<a[mid])
    bottom=mid-1;
    else
    top=mid+1;
  }
  return 1;
}


   void main()
   {
      int a[10],i,n,key,pos;
      printf("\n How many values:");
      scanf("%d",&n);
      printf("\n Enter actual values:");
      for(i=0;i<n;i++)
      {
         scanf("%d",&a[i]);
      }
      printf("\n enter the value you want to search:");
      scanf("%d",&key);
      if(pos==1)
      printf("\n Element is not found");
      else
      printf("element is found");
   }
