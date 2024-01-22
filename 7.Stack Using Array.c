#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
    int capacity;
    int top;
    int *ptr;
};

struct stack* createStack(int cap)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = cap;
    s->top = -1;
    s->ptr = (int*)malloc(sizeof(int)*cap);
    return s;
}

void push(struct stack *s,int data)
{
    if(s->top<s->capacity-1)
    {
        s->top+=1;
        s->ptr[s->top] = data;
    }
    else
       printf("Overflow");
}

int pop(struct stack *s)
{
    if(s->top!=-1)
    {
        int data = s->ptr[s->top];
        s->top-=1;
        return data;
    }
    return -1;
}

int peek(struct stack *s)
{
    if(s->top>=0)
       return s->ptr[s->top];
}

void viewStack(struct stack *s)
{
    if(s==NULL || s->top<0)
       printf("Stack is Empty");
    else
    {
        int i;
        for(i=0;i<=s->top;i++)
           printf("%d ",s->ptr[i]);
        printf("\n");
    }
}

int menu()
{
    int choice;
    printf("\n\n1.CreateStack()");
    printf("\n2.Push()");
    printf("\n3.Pop()");
    printf("\n4.Peek()");
    printf("\n5.Exit");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    return choice;
}
void main()
{
    struct stack *s=NULL;
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
            viewStack(s);
        switch(menu())
        {
            case 1:
               printf("Enter Size to create Stack:");
               scanf("%d",&size);
               s=createStack(size);
               break;

            case 2:
               printf("Enter Data:");
               scanf("%d",&data);
               push(s,data);
               break;

            case 3:
               reg=pop(s);
               break;

            case 4:
               reg=peek(s);
               break;

            case 5:
               exit(0);

            default:
               printf("Invalid Choice");
        }
    }
}
