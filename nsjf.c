#include<stdio.h>
void main()
{
 int p[10],at[10],bt[10],st[10],ft[10],wt[10],tt[10],n,i,j,temp;
 float awt=0,att=0;
 printf("Process schedular using sjf\n");
 printf("how many process:");
 scanf("%d",&n);
 printf("Enter details of each process.....:\n");
 for(i=0;i<n;i++)
 {
    printf("process %d:",i+1);
    p[i]=i+1;
    printf("\n\t arrival= ");
    scanf("%d",&at[i]);
    printf("\t burst= ");
    scanf("%d",&bt[i]);
   } 
    for(i=0;i<n;i++)
    for(j=0;j<n-1;j++)
    {
       if(at[j]>at[j+1])
       {
          temp=p[j];
          p[j]=p[j+1];
          p[j+1]=temp;
          
          temp=at[j];
          at[j]=at[j+1];
          at[j+1]=temp;
          
          temp=bt[j];
          bt[j]=bt[j+1];
          bt[j+1]=temp;
       }
    }
    
    for(i=1;i<n;i++)
    for(j=1;j<n-1;j++)
    {
      if(bt[j]>bt[j+1])
      {
         temp=p[j];
          p[j]=p[j+1];
          p[j+1]=temp;
          
          temp=at[j];
          at[j]=at[j+1];
          at[j+1]=temp;
          
          temp=bt[j];
          bt[j]=bt[j+1];
          bt[j+1]=temp; 
      }
    }
    int bsum=0;
    bsum=bt[0];
    for(i=1;i<n;i++)
    {
      for(j=i;j<n-1;j++)
      {
        if(at[j]<=bsum)
        {
          if(i==j)
          break;
          else if(i==j+1)
          {
          temp=p[j];
          p[j]=p[i];
          p[i]=temp;
          
          temp=at[j];
          at[j]=at[i];
          at[i]=temp;
          
          temp=bt[j];
          bt[j]=bt[i];
          bt[i]=temp;
          break;
          }
          else
          {
            while(j!=i)
            {
          temp=p[j];
          p[j]=p[j-1];
          p[j-1]=temp;
          
          temp=at[j];
          at[j]=at[j-1];
          at[j-1]=temp;
          
          temp=bt[j];
          bt[j]=bt[j-1];
          bt[j-1]=temp;
          j--;
            }
            break;
          }
        }
      }
      bsum=bsum+bt[i];
    }
    st[0]=at[0];
    ft[0]=st[0]+bt[0];
    for(i=1;i<n;i++)
    {
      st[i]=st[i-1]+bt[i-1];
      ft[i]=st[i]+bt[i];
    }
    for(i=0;i<n;i++)
    {
      wt[i]=st[i]-at[i];
      tt[i]=ft[i]-at[i];
    }
    for(i=0;i<n;i++)
    {
    awt=awt+wt[i];
    att=att+tt[i];
    
    }
    awt=awt/n;
    att=att/n;
    
    printf("\n *** Tabble ****\n");
    printf("\t process\tAT\tBT\tSt\tFt\tWT\tTT\n");
    for(i=0;i<n;i++)
    {
           printf("\tp%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],st[i],ft[i],wt[i],tt[i]);
       
    }
    printf("\n");
    printf("\n Average Waiting time=%2f",awt);
    printf("\n Average Turnaroud time=%2f",att);
    printf("\n");
    
 }

