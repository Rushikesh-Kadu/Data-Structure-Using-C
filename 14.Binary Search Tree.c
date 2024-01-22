#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BST
{
    int item;
    struct BST *left;
    struct BST *right;
};

void insertion(struct BST **root,int data)
{
    struct BST *n = (struct BST*)malloc(sizeof(struct BST));
    n->item = data;
    n->left = NULL;
    n->right = NULL;
    if(*root==NULL)
       *root = n;
    else
    {
        struct BST *r = *root;
        while(1)
        {
            if(r->item==data)
            {
                printf("Duplicate Items are not allowed");
                free(n);
                break;
            }
            else if(r->item>data)
            {
                if(r->left==NULL)
                {
                   r->left = n;
                   break;
                }
                r = r->left;
            }
            else
            {
                if(r->right==NULL)
                {
                    r->right = n;
                    break;
                }
                r = r->right;
            }
        }
    }
}

void deletion(struct BST **root,int data)
{
    if(*root==NULL)
       printf("BST is Empty");
    else
    {
        struct BST *r = *root;
        struct BST *parptr = NULL;
        while(r!=NULL && r->item!=data)
        {
            if(r->item<data)
            {
                parptr = r;
                r=r->right;
            }
            else
            {
                parptr = r;
                r=r->left;
            }
        }
        if(r==NULL)
           printf("Data not Found");
        else
        {
            if(r->left==NULL && r->right==NULL)
            {
                // zero Child
                if(parptr==NULL)
                    *root=NULL;
                else if(parptr->left==r)
                    parptr->left=NULL;
                else
                    parptr->right=NULL;
                free(r);

            }
            else if(r->left==NULL || r->right==NULL)
            {
                // one Child
                if(parptr==NULL)
                {
                    if(r->right!=NULL)
                        *root = r->right;
                    else
                        *root = r->left;
                }
                else if(parptr->right==r)
                {
                    if(r->right!=NULL)
                       parptr->right=r->right;
                    else
                       parptr->right = r->left;
                }
                else
                {
                    if(r->right!=NULL)
                       parptr->left = r->right;
                    else
                       parptr->left = r->left;
                }
                free(r);
            }
            else
            {
                // two Child
                struct BST *parsuc = r;
                struct BST *suc=r->right;
                while(suc->left!=NULL)
                {                    
                    parsuc = suc;
                    suc = suc -> left;
                }             
                r->item = suc->item;
                if(parsuc->left==suc)
                   parsuc->left = suc->right;
                else
                   parsuc->right = suc->right;
                free(suc);
            }
        }
    }
}

void preOrder(struct BST *r)
{
    if(r!=NULL)
    {
        printf("%d ",r->item);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct BST *r)
{
    if(r!=NULL)
    {
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ",r->item);

    }
}

void inOrder(struct BST *r)
{
    if(r!=NULL)
    {
        inOrder(r->left);
        printf("%d ",r->item);
        inOrder(r->right);
    }
}


int menu()
{
    int choice;
    printf("\n\n1.Insertion");
    printf("\n2.Deletion");
    printf("\n3.Preorder");
    printf("\n4.Inorder");
    printf("\n5.Postorder");
    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    return choice;
}
void main()
{
    struct BST *root=NULL;
    int data;
    while(1)
    {
        system("cls");
        inOrder(root);
        switch(menu())
        {
            case 1:
               printf("Enter Data:");
               scanf("%d",&data);
               insertion(&root,data);
               system("cls");
               break;
            case 2:
               printf("Enter Data to Remove:");
               scanf("%d",&data);
               deletion(&root,data);
               system("cls");
               break;
            case 3:
               system("cls");
               printf("PreOrder:");
               preOrder(root);
               printf("\n");
               break;
            case 4:
               system("cls");
               printf("InOrder:");
               inOrder(root);
               printf("\n");
               break;
            case 5:
               system("cls");
               printf("PostOrder:");
               postOrder(root);
               printf("\n");
               break;
        }
    }
}
