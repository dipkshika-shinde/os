#include<stdio.h>
int main()
{
    printf("Before forking\n");
    fork();
    printf("After forking\n ");
    
    return 0;
}
