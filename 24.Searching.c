#include<stdio.h>
#include<conio.h>

int linear_search(int *ptr,int data,int s)
{
    if(ptr[s-1]==data)
        return s-1;
    else if(s==-1)
        return -1;
    return linear_search(ptr,data,s-1);
}

int binary_search(int *ptr,int data,int l,int u)
{
    if(l<=u)
    {
        int m = (l+u)/2;
        if(data==ptr[m])
           return m;
        else if(data<ptr[m])
           return binary_search(ptr,data,l,m-1);
        else
           return binary_search(ptr,data,m+1,u);
    }
    else
       return -1;
}
void main()
{
    int ptr[] = {1,2,3,4,5,6,7,8,9,100};
    int i;
    printf("%d",binary_search(ptr,100,0,9));
}