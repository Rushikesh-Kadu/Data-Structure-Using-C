#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "10.Queue using array.c"
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

void bfs(struct Graph *G)
{
    if(G!=NULL)
    {
        struct Queue *Q=createQueue(G->V);
        struct node *temp=NULL;
        int i,v;
        //1.iNITIALIZE ALL NODES TO THE READY STATE

        for(i=0;i<G->V;i++)
           G->status[i] = READY;

        //2.PUT THE STARTING NODE IN QUEUE AND CHANGE IT'S STATUS TO THE WAITING STATE
        enQueue(Q,1);
        G->status[0] = WAITING;

        //3.LOOP FOR STEP 4 AND 5 UNITL QUEUE DOESN'T BECOME EMPTY
        while(!emptyQueue(Q))
        {
            // 4.Remove Front node n of queue. process it and change it's status to the processed state
            v = deQueue(Q);
            printf(" V%d",v);
            G->status[v-1]=PROCESSED;

            temp = G->Adj[v-1];
            while(temp)
            {
                //5.Add to the rear of queue all the adjacent nodes of N that are in the ready state and change their status to the waiting state.
                if(G->status[temp->v_no-1]==READY)
                {
                    enQueue(Q,temp->v_no);
                    G->status[temp->v_no-1] = WAITING;
                }
                temp=temp->next;
            }
        }
    }
}


void main()
{
    struct Graph *G=NULL;
    G = createGraph(6,9);
    printList(G);
    bfs(G);
}
