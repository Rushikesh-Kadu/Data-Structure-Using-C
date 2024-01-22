#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Priority_Queue
{
    int item;
    int pr_no;
    struct Priority_Queue *next;
};

void enQueue(struct Priority_Queue **F,struct Priority_Queue **R,int pr_no,int data)
{
    struct Priority_Queue *n = (struct Priority_Queue*)malloc(sizeof(struct Priority_Queue));
    n->item = data;
    n->pr_no = pr_no;
    if(*F==NULL)
    {
        n->next = NULL;
        *F=*R=n;
    }
    else
    {
        struct Priority_Queue *temp = *F;
        if(temp->pr_no>pr_no)
        {
            n->next = temp;
            *F = n;
        }
        else
        {
            while(temp->next!=NULL && temp->next->pr_no<pr_no)
                 temp = temp->next;
            n->next = temp->next;
            temp->next = n;
        }
        if(n->next==NULL)
            *R=n;
    }
}

void deQueue(struct Priority_Queue **F,struct Priority_Queue **R)
{
    if(*F==NULL)
      printf("Underflow");
    else
    {
        struct Priority_Queue *temp = *F;
        if(*F==*R)
           *F=*R=NULL;
        else
            *F=temp->next;
        free(temp);
    }
}

void release(struct Priority_Queue **F,struct Priority_Queue **R)
{
    while(*F)
       deQueue(F,R);
}

void viewPrQueue(struct Priority_Queue *F)
{
    if(F==NULL)
       printf("Priority Queue is Empty");
    else
    {
        while(F)
        {
            printf("%d ",F->item);
            F = F->next;
        }
    }
}

int menu()
{
    int choice;
    printf("\n\n1.EnQueue");
    printf("\n2.Dequeue");
    printf("\n3.Release");
    printf("\n4.Exit");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    return choice;
}
void main()
{
    struct Priority_Queue *front=NULL,*rear=NULL;
    int data,no;
    while(1)
    {
        system("cls");
        viewPrQueue(front);
        switch(menu())
        {
            case 1:
               printf("Enter Data:");
               scanf("%d",&data);
               printf("Enter Priority No:");
               scanf("%d",&no);
               enQueue(&front,&rear,no,data);
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
