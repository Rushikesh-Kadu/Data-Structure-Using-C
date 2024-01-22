#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *prev;
    struct node *next;
};

void insertFirst(struct node **s,int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    if(*s==NULL)
        n->prev=n->next=n;
    else
    {
        n->next = *s;
        n->prev = (*s)->prev;
        (*s)->prev->next = n;
        (*s)->prev = n;
    }
    *s = n;
}

void insertLast(struct node **s,int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    if(*s==NULL)
    {
       n->prev=n->next=n;
       *s = n;
    }
    else
    {
        n->prev = (*s)->prev;
        n->next = *s;
        (*s)->prev->next= n;
        (*s)->prev = n;
    }
}

struct node* searchItem(struct node *s,int data)
{
    while(s)
    {
        if(s->item == data)
          return s;
        s=s->next;
    }
    return (struct node*)-1;
}

void insertAfter(struct node *s,int after,int data)
{
    if(s!=NULL)
    {
        struct node *t = searchItem(s,after);
        if(t!=(struct node*)-1)
        {
            struct node *n = (struct node*)malloc(sizeof(struct node));
            n->item = data;
            n->next = t->next;
            n->prev = t;
            t->next->prev = n;
            t->next = n;
        }
    }
}

void removeFirst(struct node **s)
{
    if(*s==NULL)
      printf("Circular Doubly Linked List is Empty");
    else
    {
        struct node *temp = *s;
        if(temp->next == temp)
            *s = NULL;
        else
        {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            *s = temp->next;
        }
        free(temp);
    }
}

void removeLast(struct node **s)
{
    if(*s==NULL)
       printf("Circular Doubly Linked List is Empty");
    else
    {
        struct node *temp = *s;
        if(temp->next==temp)
           *s = NULL;
        else
        {
            struct node *first = temp;
            temp = temp->prev;
            temp->prev->next=temp->next;
            first->prev = temp->prev;
        }
        free(temp);
    }
}

void removeNode(struct node **s,int data)
{
    if(*s==NULL)
       printf("Circular Doubly Linked List is Empty");
    else
    {
        struct node *t = searchItem(*s,data);
        if(t!=(struct node*)-1 && t->next==t)
            *s = NULL;
        else if(t!=(struct node*)-1)
        {
            t->prev->next = t->next;
            t->next->prev = t->prev;
            if(*s==t)
              *s = t->next;
        }
        free(t);
    }
}

void viewList(struct node *s)
{
    if(s==NULL)
       printf("Circular Doubly Linked List is Empty");
    else
    {
        struct node *temp = s;
        do
        {
            printf("%d ",temp->item);
            temp=temp->next;
        }while(temp!=s);
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
        viewList(start);
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
                insertAfter(start,after,data);
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
