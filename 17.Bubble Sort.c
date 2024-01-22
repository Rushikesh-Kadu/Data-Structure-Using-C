#include<stdio.h>
#include<conio.h>

void bubble_sort(int *ptr,int s)
{
    int r,i,temp;
    for(r=1;r<s;r++)
    {
        for(i=0;i<=s-1-r;i++)
        {
            if(ptr[i]>ptr[i+1])
            {
                temp = ptr[i];
                ptr[i] = ptr[i+1];
                ptr[i+1] = temp;
            }
        }
    }
}

void main()
{
    int i;
    int p[10]={10,9,8,7,6,5,4,3,2,1};
    bubble_sort(p,10);
    for(i=0;i<10;i++)
       printf("%d ",p[i]);
}