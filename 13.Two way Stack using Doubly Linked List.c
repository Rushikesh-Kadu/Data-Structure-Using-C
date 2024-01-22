#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
    int item;
    struct stack *prev;
    struct stack *next;
};

void push(struct stack **t1,struct stack **t2,int s_no,int data)
{
    struct stack *n = (struct stack*)malloc(sizeof(struct stack));
    n->item = data;
    if(s_no==1)
    {
        if(*t1==NULL)
        {
            n->prev = NULL;
            n->next = *t2;
            *t1 = n;
        }
        else
        {  
            n->next = (*t1)->next;
            n->prev = *t1;
            if((*t1)->next!=NULL)
               (*t1)->next->prev = n;
            (*t1)->next = n;
            *t1 = n;
        }
    }
    else if(s_no==2)
    {
        if(*t2==NULL)
        {
            n->next = NULL;
            if(*t1!=NULL)
            {
                n->prev = *t1;
                (*t1)->next = n;
            }
            else
                n->prev = NULL;
            *t2 = n;
        }
        else
        {
            n->next = *t2;
            n->prev = *t1;
            if(*t1!=NULL)
               (*t1)->next = n;
            (*t2)->prev = n;
            *t2 = n;            
        }
    }
    else
       free(n);         // If Stack no is Invalid 
}

void pop(struct stack **t1,struct stack **t2,int s_no)
{
    if(s_no==1)
    {
        if(*t1!=NULL)
        {
            struct stack *temp = *t1;
            if(temp->prev==NULL)
            {
                if(temp->next!=NULL)
                    temp->next->prev = NULL;
                *t1 = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                if(temp->next!=NULL)
                   temp->next->prev = temp->prev;
                *t1 = temp->prev;
            }
            free(temp);
        }
    }
    else if(s_no==2)
    {
        if(*t2!=NULL)
        {
            struct stack *temp = *t2;
            if(temp->next==NULL)
            {
                if(temp->prev!=NULL)
                    temp->prev->next = NULL;
                *t2 = NULL;
            }
            else
            {
                temp->next->prev = temp->prev;
                if(temp->prev!=NULL)
                   temp->prev->next = temp->next;
                *t2 = temp->next;
            }
            free(temp);
        }
    }
}

void viewStack(struct stack *t1,struct stack *t2)
{
    if(t1==NULL)
      printf("T1 stack is empty ");
    else
      while(t1)
      {
        printf("%d ",t1->item);
        t1 = t1->prev;
      }

    if(t2 ==NULL)
      printf("T2 stack is empty ");
    else
    {
        while(t2)
        {
            printf("%d ",t2->item);
            t2 = t2->next;
        }
    }
}

int peek(struct stack *t1,struct stack *t2,int s_no)
{
    if(s_no==1)
    {
        if(t1!=NULL)
            return t1->item;
        return 0;
    }
    else if(s_no==2)
    {
        if(t2!=NULL)
            return t2->item;
        return 0;
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
    struct stack *top1=NULL,*top2=NULL;
    int data,reg=0,size,s_no;
    while(1)
    {
        system("cls");
        if(reg!=0)
        {
            printf("%d ",reg);
            reg=0;
        }
        else
            viewStack(top1,top2);
        switch(menu())
        {
            case 1:
               printf("Enter Stack No:");
               scanf("%d",&s_no);
               printf("Enter Data:");
               scanf("%d",&data);
               push(&top1,&top2,s_no,data);
               break;

            case 2:
               printf("Enter stack number to pop element:");
               scanf("%d",&s_no);
               pop(&top1,&top2,s_no);
               break;

            case 3:
               printf("Enter stack number to pop element:");
               scanf("%d",&s_no);
               reg=peek(top1,top2,s_no);
               break;

            case 4:
               exit(0);

            default:
               printf("Invalid Choice");
        }
    }
}
