#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Queue
{
    int item;
    struct Queue *next;
};

void enQueue(struct Queue **F,struct Queue **R,int data)
{
    struct Queue *n = (struct Queue*)malloc(sizeof(struct Queue));
    n->item = data;
    n->next = NULL;
    if(*R==NULL)
        *F = *R = n;
    else
    {
        (*R)->next = n;
        *R = n;
    }
}

int deQueue(struct Queue **F,struct Queue **R)
{
    if(*F==NULL)
       printf("Underflow");
    else
    {
        struct Queue *temp = *F;
        int data = temp->item;
        if(*F==*R)
            *F=*R=NULL;
        else
            *F = temp->next;
        free(temp);
        return data;
    }
}

void viewQueue(struct Queue *F)
{
    if(F==NULL)
       printf("Queue is Empty");
    else
    {
        while(F)
        {
            printf("%d ",F->item);
            F = F->next;
        }
    }
}

void release(struct Queue **F,struct Queue **R)
{
    while(*F)
    {
        deQueue(F,R);
    }
}

int menu()
{
    int choice;
    printf("\n\n1.EnQueue");
    printf("\n2.DeQueue");
    printf("\n3.Release");
    printf("\n4.Exit");
    printf("\nEnter Choice:");
    scanf("%d",&choice);
    return choice;
}
void main()
{
    struct Queue *front=NULL,*rear=NULL;
    int data,reg=0;
    while(1)
    {
        system("cls");
        viewQueue(front);
        switch(menu())
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                enQueue(&front,&rear,data);
                break;

            case 2:
                deQueue(&front,&rear);
                break;

            case 3:
                release(&front,&rear);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice");
        }
    }
}
