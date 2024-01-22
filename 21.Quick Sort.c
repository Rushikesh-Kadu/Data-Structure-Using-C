#include<stdio.h>
#include<conio.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int quick(int *p,int l,int u)
{
    int left,right,loc,temp;
    left = loc = l;
    right = u;
    while(left<right)
    {
        while(left<right && p[loc]<p[right])
           right--;
        if(left==right)
           break;
        else
        {
            swap(&p[loc],&p[right]);
            loc = right;
        }

        while(left<right && p[left]<p[loc])
            left++;
        if(left==right)
           break;
        else
        {
            swap(&p[left],&p[loc]);
            loc = left;
        }
    }
    return loc;
}


void quick_sort(int *ptr,int l,int u)
{
    int loc;
    loc = quick(ptr,l,u);
    if(l<loc-1)
       quick_sort(ptr,l,loc-1);
    if(loc+1<u)
       quick_sort(ptr,loc+1,u);
}

void main()
{
    int i;
    int p[10]={10,9,8,7,6,5,4,3,2,1};
    quick_sort(p,0,9);
    for(i=0;i<10;i++)
       printf("%d ",p[i]);
}