#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Queue
{
    int capacity;
    int front,rear;
    int *ptr;
};

struct Queue* createQueue(int cap)
{
    struct Queue *Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->capacity = cap;
    Q->front = Q->rear = -1;
    Q->ptr = (int*)malloc(sizeof(int)*cap);
    return Q;
}

int emptyQueue(struct Queue *Q)
{
    if(Q==NULL || Q->rear==-1)
        return 1;
    return 0;
}

void enQueue(struct Queue *Q,int data)
{
    if(Q->front==0 && Q->rear==Q->capacity-1 || Q->rear+1==Q->front)
        printf("Overflow");
    else
    {   if(Q->rear==-1)
            Q->rear = Q->front = 0;
        else if(Q->rear==Q->capacity-1)
            Q->rear = 0;
        else
            Q->rear +=1;
        Q->ptr[Q->rear] = data;
    }
}

int deQueue(struct Queue *Q)
{
    if(Q==NULL || Q->front==-1)
       printf("Underflow");
    else
    {
        int data;
        data = Q->ptr[Q->front];
        if(Q->front==Q->rear)
            Q->front = Q->rear = -1;
        else if(Q->front==Q->capacity-1)
            Q->front = 0;
        else
            Q->front+=1;
        return data;
    }
}

void viewQueue(struct Queue *Q)
{
    if(Q==NULL || Q->front==-1)
       printf("Queue is Empty");
    else
    {
        int i;
        if(Q->rear<Q->front)
        {
            for(i=Q->front;i<=Q->capacity-1;i++)
               printf("%d ",Q->ptr[i]);
            for(i=0;i<=Q->rear;i++)
               printf("%d ",Q->ptr[i]);
        }
        else
        {
            for(i=Q->front;i<=Q->rear;i++)
               printf("%d ",Q->ptr[i]);
        }
    }
}

// int menu()
// {
//     int choice;
//     printf("\n\n1.CreateQueue");
//     printf("\n2.Enqueue");
//     printf("\n3.Dequeue");
//     printf("\n4.Exit");
//     printf("\nEnter Your Choice:");
//     scanf("%d",&choice);
//     return choice;
// }
// void main()
// {
//     struct Queue *Q=NULL;
//     int data,reg=0,size;
//     while(1)
//     {
//         system("cls");
//         if(reg!=0)
//         {
//             printf("%d ",reg);
//             reg=0;
//         }
//         else
//             viewQueue(Q);
//         switch(menu())
//         {
//             case 1:
//                printf("Enter Size:");
//                scanf("%d",&size);
//                Q=createQueue(size);
//                break;

//             case 2:
//                printf("Enter Data:");
//                scanf("%d",&data);
//                enQueue(Q,data);
//                break;

//             case 3:
//                reg=deQueue(Q);
//                break;

//             case 4:
//                exit(0);

//             default:
//                printf("Invalid Choice");

//         }
//     }
// }
