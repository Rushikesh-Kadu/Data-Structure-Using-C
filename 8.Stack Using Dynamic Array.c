#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Stack
{
    int capacity,top;
    int *ptr;
};

struct Stack* createStack(int cap)
{
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->capacity = cap;
    s->top = -1;
    s->ptr = (int*)malloc(sizeof(int)*cap);
    return s;
}

void doubleStack(struct Stack *s)
{
    int *ptr1 = (int*)malloc(sizeof(int)*s->capacity*2);
    int i;
    for(i=0;i<=s->top;i++)
        ptr1[i] = s->ptr[i];
    s->capacity*=2;
    free(s->ptr);
    s->ptr = ptr1;    
} 

void halfStack(struct Stack *s)
{
    int *ptr1 = (int*)malloc(sizeof(int)*s->capacity/2);
    int i;
    for(i=0;i<=s->top;i++)
        ptr1[i] = s->ptr[i];
    s->capacity/=2;
    free(s->ptr);
    s->ptr = ptr1;   
}

void push(struct Stack *s,int data)
{
    if(s->top==s->capacity-1)
        doubleStack(s);
    s->top+=1;
    s->ptr[s->top] = data;
    
}

int pop(struct Stack *s)
{
    if(s->top<0)
      printf("Underflow");
    else
    {
        int data = s->ptr[s->top];
        s->top-=1;
        if(s->top<s->capacity/2)
            halfStack(s);
        return data;
    }
    return -1;
}

int peek(struct Stack *s)
{
    if(s->top>=0)
       return s->ptr[s->top];
}

int emptyStack(struct Stack *s)
{
    if(s==NULL || s->top==-1)
       return 1;
    return 0;
}

void viewStack(struct Stack *s)
{
    if(s==NULL || s->top<0)
      printf("Stack is Empty");
    else
    {
        int i;
        for(i=0;i<=s->top;i++)
            printf("%d ",s->ptr[i]);
        printf("\t\t %d %d",s->capacity,s->top);
    }
}

// int menu()
// {
//     int choice;
//     printf("\n\n1.CreateStack()");
//     printf("\n2.Push()");
//     printf("\n3.Pop()");
//     printf("\n4.Peek()");
//     printf("\n5.Exit");
//     printf("\nEnter Your Choice:");
//     scanf("%d",&choice);
//     return choice;
// }
// void main()
// {
//     struct Stack *s=NULL;
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
//             viewStack(s);
//         switch(menu())
//         {
//             case 1:
//                printf("Enter Size to create Stack:");
//                scanf("%d",&size);
//                s=createStack(size);
//                break;

//             case 2:
//                printf("Enter Data:");
//                scanf("%d",&data);
//                push(s,data);
//                break;

//             case 3:
//                reg=pop(s);
//                break;

//             case 4:
//                reg=peek(s);
//                break;

//             case 5:
//                exit(0);

//             default:
//                printf("Invalid Choice");
//         }
//     }
// }
