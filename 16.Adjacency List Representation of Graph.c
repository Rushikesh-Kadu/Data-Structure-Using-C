#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int v_no;
    struct node *next;
};

struct Graph
{
    int V;
    struct node **Adj;
};

struct Graph* createGraph(int v,int e)
{
    int i,j,k;
    struct node *n = NULL;
    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
    G->V = v;
    G->Adj = (struct node**)malloc(sizeof(struct node*)*v);
    for(i=0;i<v;i++)
    {
       n = (struct node*)malloc(sizeof(struct node));
       n->v_no = i+1;
       n->next = NULL;
       G->Adj[i]=n;
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

void main()
{
    struct Graph *G;
    G=createGraph(5,6);
    printList(G);
}
