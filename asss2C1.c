#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/wait.h>

void toks(char *s, char*tok[])
{
   int i=0;
   char *p;
   p=strtok(s," ");
   while(p!=NULL)
   {
      tok[i++]=p;
      p=strtok(NULL," ");
   }
   tok[i]=NULL;
}

void typeline(char *fn,char *op)
{
int fh,i,j,n;
char c;
fh=open(fn,O_RDONLY);
if(fh==-1)
 {
 printf("file %s not found\n",fn);
 return;
 }
    if(strcmp(op,"a")==0)
    {
       while(read(fh,&c,1)>0)
       printf("%c",c);
       close(fh);
       return;
    }
    n=atoi(op);
    if(n>0)
    {
    i=0;
     while(read(fh,&c,1)>0)
     {
        printf("%c",c);
        if(c=='\n')
        i++;
        if(i==n)
        break;
     }
     
    }
    if(n<0)
    {
     i=0;
      while(read(fh,&c,1)>0)
      {
        if(c=='\n')
        i++;
      }
      lseek(fh,0,SEEK_SET);
      j=0;
       while(read(fh,&c,1)>0)
       {
         if(c=='\n')
        j++;
        if(j==i+n)
        break;
       }
        while(read(fh,&c,1)>0)
        {
          printf("%c",c);
        }
    }
    close(fh);
 }
int main()
{ 
    char buff[80],*args[10];
    int pid;
    while(1)
    {
       printf("myshell$");
       fflush(stdin);
       fgets(buff,80,stdin);
       buff[strlen(buff)-1]= '\0';
       toks(buff,args);
       if(strcmp(args[0],"typeline")==0)
       typeline(args[2],args[1]);
       else
       {
          pid=fork();
          if(pid>0)
          wait(NULL);
          else
          {
             if(execvp(args[0],args)==-1)
             printf("Bad cammand\n");
          }
       }
    }
    return 0;
}
