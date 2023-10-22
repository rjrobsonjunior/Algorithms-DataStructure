#include <stdio.h>
#include <stdlib.h>

#define WHITE 0;
#define GRAY 1;
#define BLACK 2;
#define NIL -1;

typedef struct graph
{
    int V; //Vertices 
    int E; //edges
    Edge** Adj; 
} Graph;

typedef struct edge
{
    int data;
    Edge* next;
} Edge;

typedef struct dfs
{
    int id;
    int finaltime;
    int time;
    int parent;
    int color;
    struct dfs* next;
} DFS;

void DFSearch(Graph* GraphA);

int DFSvisit(Graph* GraphA, Edge* edge, int index, int time);

Graph* CreateGraph(int size);

