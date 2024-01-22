#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};

void push(struct node **t,int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = *t;
    *t = n;
}

int pop(struct node **t)
{
    if(*t==NULL)
    {
       printf("Underflow");
       return -1;
    }
    else
    {
        struct node *temp = *t;
        int data = temp->item;
        *t = temp->next;
        free(temp);
        return data;
    }
}

int peek(struct node *t)
{
    if(t!=NULL)
       return t->item;
    return -1;
}

void viewStack(struct node *t)
{
    if(t==NULL)
       printf("Stack is Empty");
    else
    {
        while(t)
        {
            printf("%d ",t->item);
            t = t->next;
        }
    }
}


int menu()
{
    int choice;
    printf("\n\n1.Push()");
    printf("\n2.Pop()");
    printf("\n3.Peek()");
    printf("\n4.Exit");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    return choice;
}
void main()
{
    struct node *top=NULL;
    int data,reg=0,size;
    while(1)
    {
        system("cls");
        if(reg!=0)
        {
            printf("%d ",reg);
            reg=0;
        }
        else
            viewStack(top);
        switch(menu())
        {
            case 1:
               printf("Enter Data:");
               scanf("%d",&data);
               push(&top,data);
               break;

            case 2:
               reg=pop(&top);
               break;

            case 3:
               reg=peek(top);
               break;

            case 4:
               exit(0);

            default:
               printf("Invalid Choice");
        }
    }
}
