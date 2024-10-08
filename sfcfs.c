#include<stdio.h>
void main()
{
   void sorting(int pr[],int ar[],int br[],int n);
   void display(int pr[],int ar[],int br[],int n);
   void displayt(int pr[10],int ar[10],int br[10],int st[10],int ft[10],int wt[10],int tat[10],int n);
   int i,n,p[10],at[10],bt[10],wt[10],ft[10],st[10],tat[10];
   float avgw=0,avgt=0;
   printf("how many processes:\n");
   scanf("%d",&n);
   printf("Enter arrival time of proccesses and burst time respectively\n" :");
   for(i=0;i<n;i++)
   {
      scanf("%d %d",&at[i],&bt[i]);
      p[i]=i;
   } 
    printf("The entered processes are :\n");
    display(p,at,bt,n);
    printf("Tne Enteres processes after sorting:\n");
    sorting(p,at,bt,n);
     display(p,at,bt,n);
     st[0]=0;
     for(i=1;i<=n;i++)
     {
        st[i]=bt[i-1]+st[i-1];
     }
     for(i=0;i<n;i++)
     {
        ft[i]=st[i]+bt[i];
        wt[i]=st[i]-at[i];
        tat[i]=ft[i]-at[i];
     }
     printf("the final processes table are :\n");
     displayt(p,at,bt,st,ft,wt,tat,n);
     for(i=0;i<n;i++)
     {
       avgw=avgw+wt[i];
       avgt=avgt+tat[i];
     }
    printf("Avg. waiting time is=%2.2f\n avg.turnaround time is=%2.2f\n",avgw/n,avgt/n);
}

void sorting(int pr[],int ar[],int br[],int n)
{
   int i,j,temp;
   for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
    {
    if(ar[j]>ar[j+1])
    {
      temp=ar[j];
      ar[j]=ar[j+1];
      ar[j+1]=temp;
      
      temp=br[j];
      br[j]=br[j+1];
      br[j+1]=temp;
      
      temp=pr[j];
      pr[j]=pr[j+1];
      pr[j+1]=temp;
    }
   }
 }
}


void display(int pr[],int ar[],int br[],int n)
{
 int i;
 printf("| Process\t| Arrival time\t| Burst time |\n");
 for(i=0;i<46;i++)
 {
 printf("--");
 }
    printf("\n");
    for(i=0;i<n;i++)
    {
       printf("|p%d     \t|  %d      \t|  %d     |\n",pr[i],ar[i],br[i]);
    }
 }
 



void displayt(int pr[10],int ar[10],int br[10],int sr[10],int fn[10],int wa[10],int tatt[10],int n)
{
  int i;
  printf("|process| Arrival time|Burst time|Start time|Finish time|Waiting time|Turnaround time|\n");
  for(i=0;i<100;i++)
  {
    printf("-");
    
  }
  printf("\n");
  for(i=0;i<n;i++)
  {
     printf("| p%d      |%2d      |%2d     |%2d       |%2d     |%2d        |%2d     \n",pr[i],ar[i],br[i],sr[i],fn[i],wa[i],tatt[i]);
  }
}
