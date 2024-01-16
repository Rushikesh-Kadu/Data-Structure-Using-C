#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};

void insertFirst(struct node **l,int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    if(*l==NULL)
    {
        n->next = n;
        *l = n;
    }
    else
    {
        n->next = (*l)->next;
        (*l)->next = n;
    }
}

void insertLast(struct node **l,int data)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    if(*l==NULL)
        n->next = n;
    else
    {
        n->next = (*l)->next;
        (*l)->next = n;
    }
    *l = n;
}

struct node* searchItem(struct node *l,int data)
{
    while(l)
    {
        if(l->item == data)
            return l;
        l = l->next;
    }
    return -1;
}

void insertAfter(struct node **l,int after,int data)
{
    struct node *t = searchItem(*l,after);
    if(t!=-1)
    {
        struct node *n = (struct node*)malloc(sizeof(struct node));
        n->item = data;
        n->next = t->next;
        t->next = n;
        if(*l==t)
           *l = n;
    }
}

void removeFirst(struct node **l)
{
    if(*l==NULL)
       printf("Circular Linked List is Empty");
    else
    {
        struct node *temp = (*l)->next;
        if(temp->next == temp)
            *l = NULL;
        else
            (*l)->next = temp->next;
        free(temp);
    }
}

void removeLast(struct node **l)
{
    if(*l==NULL)
       printf("Circular Linked List is Empty");
    else
    {
        struct node *temp = (*l)->next;
        if(temp->next == temp)
        {
           *l = NULL;
           free(temp);
        }
        else
        {
            while(temp->next!=*l)
                temp = temp->next;
            temp->next = (*l)->next;
            struct node *t = *l;
            free(t);
            *l = temp;
        }
    }
}

void removeNode(struct node **l,int data)
{
    struct node *t = searchItem(*l,data);
    if(t!=-1)
    {
        struct node *temp = (*l)->next;
        if(temp->next==temp)
            *l=NULL;
        else
        {
            while(temp->next!=t)
               temp = temp->next;
            temp->next = t->next;
            if(*l == t)
               *l = temp;
        }
        free(t);
    }
}

void viewList(struct node *l)
{
    if(l==NULL)
       printf("Circular Linked List is Empty");
    else
    {
        struct node *temp = l->next;
        do
        {
            printf("%d ",temp->item);
            temp = temp->next;
        } while (temp!=l->next);

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
    struct node *last = NULL;
    int data,after;
    while(1)
    {
        system("cls");
        viewList(last);
        switch(menu())
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                insertFirst(&last,data);
                break;
            case 2:
                printf("Enter Data:");
                scanf("%d",&data);
                insertLast(&last,data);
                break;
            case 3:
                printf("Enter Data to Insert After:");
                scanf("%d",&after);
                printf("Enter Data:");
                scanf("%d",&data);
                insertAfter(&last,after,data);
                break;

            case 4:
                removeFirst(&last);
                break;
            case 5:
                removeLast(&last);
                break;
            case 6:
                printf("Enter Data:");
                scanf("%d",&data);
                removeNode(&last,data);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice");
                break;
        }
    }
}
