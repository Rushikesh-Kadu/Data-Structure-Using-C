#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "8.Stack using Dynamic Array.c"
#define READY 1
#define WAITING 2
#define PROCESSED 3

struct node
{
    int v_no;
    struct node *next;
};

struct Graph
{
    int V;
    int *status;
    struct node **Adj;
};

struct Graph* createGraph(int v,int e)
{
    int i,j,k;
    struct node *n = NULL;
    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
    G->V = v;
    G->status = (int*)malloc(sizeof(int)*v);
    G->Adj = (struct node**)malloc(sizeof(struct node*)*v);
    for(i=0;i<v;i++)
    {
       G->Adj[i]=NULL;
       G->status[i] = -1;
    }


    for(k=1;k<=e;k++)
    {
        printf("Enter Vertex Number:");
        scanf("%d%d",&i,&j);
        n = (struct node*)malloc(sizeof(struct node));
        n->v_no = j;
        n->next = G->Adj[i-1];
        G->Adj[i-1] = n;

        n = (struct node*)malloc(sizeof(struct node));
        n->v_no = i;
        n->next = G->Adj[j-1];
        G->Adj[j-1] = n;
    }
    return G;
}

void printList(struct Graph *G)
{
    if(G==NULL)
       printf("Graph is Empty");
    else
    {
        int i;
        for(i=0;i<G->V;i++)
        {
            struct node *n = G->Adj[i];
            while(n)
            {
                printf("%d ",n->v_no);
                n = n->next;
            }
            printf("\n");
        }
    }
}

void dfs(struct Graph *G)
{
    if(G!=NULL)
    {
       struct Stack *s=createStack(G->V);
       int v,i;
       struct node *temp = NULL;
       
       //1.Initialize all nodes to the READY state
       for(i=0;i<G->V;i++)
          G->status[i]=READY;

       //2.PUSH THE STARTING NODE ONTO THE STACK AND CHANGE IT'S STATUS TO THE WAITING STATE
       push(s,1);
       G->status[0]=WAITING;

       //3.Loop for the step 4 and 5 until stack is empty
       while(!emptyStack(s))
       {
           v = pop(s);
           printf(" V%d",v);
           G->status[v-1]=PROCESSED;

           temp = G->Adj[v-1];
           while(temp)
           {
               if(G->status[temp->v_no-1]==READY)
               {
                   push(s,temp->v_no);
                   G->status[temp->v_no-1]=WAITING;
               }
               temp= temp->next;
           }
       }
    }
}


void main()
{
    struct Graph *G=NULL;
    G = createGraph(6,9);
    printList(G);
    dfs(G);
}
