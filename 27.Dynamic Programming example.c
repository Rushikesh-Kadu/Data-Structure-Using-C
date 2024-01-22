#include<stdio.h>
#include<conio.h>
static int f[20];

int fib(int n)
{
    if(f[n]!=-1)
       return f[n];
    if(n==1 || n==2)
       f[n]=n-1;
    else
       f[n]=fib(n-1)+fib(n-2);
    return f[n];
}

void main()
{    
    int i;
    for(i=0;i<20;i++)
       f[i] = -1;
    printf("%d",fib(7));
}