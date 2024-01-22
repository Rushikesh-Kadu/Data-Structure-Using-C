#include<stdio.h>
#include<conio.h>

void insertion(int *Heap,int *hs,int data)
{
    int index,parIndex;
    index = *hs;
    *hs = *hs+1;
    while(index>0)
    {
        parIndex = (index-1)/2;
        if(data>Heap[parIndex])
            Heap[index] = Heap[parIndex];
        else
            break;
        index = parIndex;
    }
    Heap[index]=data;
}

int deletion(int *Heap,int *hs)
{
    int item,index,leftIndex,rightIndex,temp;
    item = Heap[0];
    temp = Heap[*hs-1];
    index = 0;
    *hs-=1;

    while(index<=*hs-1)
    {
        leftIndex = 2*index+1;
        rightIndex = 2*index+2;
        if(leftIndex>*hs-1)         // no child
             break;
        if(Heap[leftIndex]>Heap[rightIndex] || rightIndex>*hs-1)
        {
            if(temp<Heap[leftIndex])
                Heap[index] = Heap[leftIndex];
            else
                break;
            index = leftIndex; 
        }
        else
        {
            if(temp<Heap[rightIndex])
               Heap[index] = Heap[rightIndex];
            else
               break;
            index = rightIndex;
        }           
    }
    Heap[index] = temp;
    return item;
}

void sort(int *Heap,int *hs)
{
    int size = *hs;
    int j,data;
    j = *hs;
    while(*hs!=0)
    {
        data = deletion(Heap,hs);
        --j;
        Heap[j] = data;
    }
    *hs = size;
}

void main()
{
    int Heap[100],i,heapSize=0,data;
    int a[]= {100,20,90,150,70,30,10,140,80,120,40,60,110,50,130};
    for(i=0;i<15;i++)
        insertion(Heap,&heapSize,a[i]);
    for(i=0;i<heapSize;i++)
        printf("%d ",Heap[i]);
    printf("\n");
    if(heapSize>0)
        sort(Heap,&heapSize);
    for(i=0;i<heapSize;i++)
        printf("%d ",Heap[i]);
}