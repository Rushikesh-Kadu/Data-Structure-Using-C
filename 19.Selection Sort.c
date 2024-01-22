#include<stdio.h>
#include<conio.h>

int minIndex(int *ptr,int index,int s)
{
    int i,min,minIn;
    min = ptr[index];
    minIn=index;
    for(i=index+1;i<s;i++)
    {
        if(min>ptr[i])
        {
            min = ptr[i];
            minIn = i;
        }
    }
    return minIn;       
}

void selection_sort(int *ptr,int s)
{
    int i,minIn,temp;
    for(i=0;i<s-1;i++)
    {
        minIn = minIndex(ptr,i,s);
        temp = ptr[minIn];
        ptr[minIn] = ptr[i];
        ptr[i] = temp;
    }
}

void main()
{
    int i;
    int p[10]={10,9,8,7,6,5,4,3,2,1};
    selection_sort(p,10);
    for(i=0;i<10;i++)
       printf("%d ",p[i]);
}