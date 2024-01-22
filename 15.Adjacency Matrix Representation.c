#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Graph
{
    int V,E;
    int **Adj;
};

struct Graph* createGraph(int v,int e)
{
    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
    G->V = v;
    G->E = e;
    G->Adj = (int**)malloc(sizeof(int*)*v);
    int i,j,k;
    for(i=0;i<v;i++)
    {
        G->Adj[i] = (int*)malloc(sizeof(int)*v);
        for(j=0;j<v;j++)
            G->Adj[i][j] = 0;
    }
    for(k=1;k<=e;k++)
    {
        printf("Enter Vertex Number:");
        scanf("%d%d",&i,&j);
        G->Adj[i-1][j-1] = 1;
        G->Adj[j-1][i-1] = 1;
    }
    return G;
}

void printMatrix(struct Graph *G)
{
    if(G==NULL)
      printf("Adjancency Matrix is Empty");
    else
    {
        int i,j;
        for(i=0;i<G->V;i++)
        {
            for(j=0;j<G->V;j++)
               printf("%d ",G->Adj[i][j]);
            printf("\n");
        }
    }
}


void main()
{
    struct Graph *G;
    G=createGraph(5,6);
    printMatrix(G);
}
