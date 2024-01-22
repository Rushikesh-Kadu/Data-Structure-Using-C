#include<stdio.h>
#include<conio.h>

void TOH(int n,int beg,int aux,int end)
{
    static int i;
    if(n>0)
    {
        TOH(n-1,beg,end,aux);
        printf("%d)%c->%c\n",++i,beg,end);
        TOH(n-1,aux,beg,end);
    }
}

void main()
{
    TOH(5,'A','B','C');
}