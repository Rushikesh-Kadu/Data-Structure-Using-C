#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int item;
    struct node *next;
};

void insertFirst(struct node **s,int data)
{
    struct node *n = malloc(sizeof(struct node));
    n->item = data;
    n->prev = NULL;
    if(*s==NULL)
        n->next = *s;
    else
    {
        (*s)->prev=n;
        n->next = *s;
    }
    *s = n;
}

void insertLast(struct node **s,int data)
{
    struct node *n = malloc(sizeof(struct node));
    n->item = data;
    n->next=NULL;
    if(*s==NULL)
    {
        n->prev = NULL;
        *s = n;
    }
    else
    {
        struct node *temp = *s;
        while(temp->next!=NULL)
           temp = temp->next;
        n->prev = temp;
        temp->next = n;
    }
}

struct node* searchItem(struct node *s,int data)
{
    if(s!=NULL)
    {
        while(s)
        {
            if(s->item == data)
               return s;
            s=s->next;
        }
    }
    return (struct node*)-1;
}

void insertAfter(struct node **s,int after,int data)
{
    struct node *t = searchItem(*s,after);
    if(t!=(struct node*)-1)
    {
        struct node *n = malloc(sizeof(struct node));
        n->item = data;
        n->next = t->next;
        n->prev = t;
        if(t->next!=NULL)
            t->next->prev=n;
        t->next = n;
    }
}

void removeFirst(struct node **s)
{
    if(*s==NULL)
       printf("Doubly Linked List is Empty");
    else
    {
        struct node *temp = *s;
        if(temp->next!=NULL)
            temp->next->prev=NULL;
        *s = temp->next;
        free(temp);
    }
}

void removeLast(struct node **s)
{
    if(*s==NULL)
       printf("Doubly Linked List is Empty");
    else
    {
        struct node *temp = *s;
        if(temp->next==NULL)
        {
             *s=NULL;
             free(temp);
        }
        else
        {
            while(temp->next->next!=NULL)
               temp = temp->next;
            free(temp->next);
            temp->next = NULL;
        }
    }
}

void removeNode(struct node **s,int data)
{
    if(*s==NULL)
      printf("Doubly Linked is Empty");
    else
    {
        struct node *t = searchItem(*s,data);
        if(t!=(struct node*)-1)
        {
            if(t->prev!=NULL)
                t->prev->next = t->next;
            if(t->next!=NULL)
                t->next->prev = t->prev;
            if(*s==t)
                *s = t->next;
            free(t);
        }
    }
}

void displayList(struct node *s)
{
    if(s==NULL)
      printf("Doubly Linked List is Empty");
    else
      while(s)
      {
           printf("%d ",s->item);
           s=s->next;
      }
}


int menu()
{
    int choice;
    printf("\n\n1.Insert First");
    printf("\n2.Insert Last");
    printf("\n3.Insert After");
    printf("\n4.Remove First");
    printf("\n5.Remove Last");
    printf("\n6.Remove Node");
    printf("\n7.Exit");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    return choice;
}

void main()
{
    struct node *start = NULL;
    int data,after;
    while(1)
    {
        system("cls");
        displayList(start);
        switch(menu())
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                insertFirst(&start,data);
                break;
            case 2:
                printf("Enter Data:");
                scanf("%d",&data);
                insertLast(&start,data);
                break;
            case 3:
                printf("Enter Data to Insert After:");
                scanf("%d",&after);
                printf("Enter Data:");
                scanf("%d",&data);
                insertAfter(&start,after,data);
                break;

            case 4:
                removeFirst(&start);
                break;
            case 5:
                removeLast(&start);
                break;
            case 6:
                printf("Enter Data:");
                scanf("%d",&data);
                removeNode(&start,data);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice");
                break;
        }
    }
}
