#include<stdio.h>
#include<conio.h>

void insertion_sort(int *ptr,int s)
{
    int i,j,temp;
    for(i=1;i<s;i++)
    {
        j = i-1;                            // 10 9 8 7 6
        while(j!=-1)                        // 9 10 8 7 6
        {                                   // 9 8 10 7 6                8 9 10 7 6
            if(ptr[j]>ptr[j+1])             // 
            {
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
            else
               break;
            j-=1;
        }
    }
}

void main()
{
    int i;
    int p[10]={10,9,8,7,6,5,4,3,2,1};
    insertion_sort(p,10);
    for(i=0;i<10;i++)
       printf("%d ",p[i]);
}