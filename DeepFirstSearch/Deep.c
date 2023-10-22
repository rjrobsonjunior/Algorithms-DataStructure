#include "Deep.h"

int DFSearch(Graph* GraphA)
{
    int u;
    DFS *V = (DFS *)malloc(GraphA->V * sizeof(DFS));
    for (u = 0; u < GraphA->V; u++) {
        V[u].color = WHITE;
        V[u].parent = NIL;
    }
    int time = 0;
    for (u = 0; u < GraphA->V; u++) 
    {
        if( V[u].color == WHITE )
        { 
            DFS_Visit (GraphA, u, V, &time);
        }
    }
}
int DFSvisit(Graph* GraphA, DFS* V, int index, int* time)
{
    (*time)++;
    V[index].finaltime;
    Edge *l = GraphA->Adj[index];

    while( l != NULL)
    {
        if(!V[l->data].color)
        {
            V[l->data].parent = index;
            V[l->data].color = V[index].color;
            if(DFS_Visit(GraphA, V, l->data, time ))
            {
                return 1;
            }
        }
        if(V[l->data].color == V[u].color)
        {
            return 1;
        }
        l = l->next;
    }
    V[index].finaltime = (*time);
    (*time)++;
    return 0;
}

Graph* CreateGraph(int size)
{
   int v;
   Graph *G = (Graph *)malloc(sizeof(Graph));
   G->E = 0;
   G->V = size;
   G->Adj = (Edge **)malloc(size * sizeof(Edge *));
   for (v = 0; v < G->V; v++) 
   {
      G->Adj[v] = NULL;
   }
   return G;
}

/*

//==================
//==Exercício 2===//
//==================

#define BRANCO 1
#define CINZA  2
#define PRETO  3
#define VERMELHO  4

/Estrutura para um vértice em uma lista encadeada: /
typedef struct dfs {
   int d;
   int f;
   int cor;
   int pai;
   int identificador; //Identificador do vértice armazenado no nó. //   
   struct dfs *proximo; // Próximo nó na lista encadeada. //
} DFS;


//=== Impressão arestas =====//
void Busca_Profundidade (Grafo *G) {
   int u;
   int tempo = 0;
   //lista de vértices do grafo
   DFS *V = (DFS *)malloc(G->V * sizeof(DFS));

   //inicialização para o DFS
   for (u = 0; u < G->V; u++) {
      V[u].cor = BRANCO;
      V[u].pai = -1;
   }
   for (u = 0; u < G->V; u++) {
      if (V[u].cor == BRANCO) {
         DFS_Visit (G, V, u, &tempo); 
      }
   }
   printf("Busca em profundidade:\n");
   for (u = 0; u < G->V; u++) {
      printf("%2d = [d : %2d, f : %2d, pai : %2d]\n", u, V[u].d, V[u].f, V[u].pai);
   }
}

// //
void DFS_Visit (Grafo *G, DFS *V, int u, int *tempo) {
   V[u].cor = CINZA;
   *tempo = (*tempo) + 1; 
   V[u].d = (*tempo);
   DFS *v;
   for (v = G->listaAdj[u]; v != NULL; v = v->proximo) {
      if (V[v->identificador].cor == BRANCO) {
         printf("Aresta arvore: %2d - %2d\n", u, v->identificador);
         V[v->identificador].pai = u;
         DFS_Visit (G, V, v->identificador, tempo);
      }
      else {
         printf("Aresta outra : %2d - %2d\n", u, v->identificador);
      }
   }
   V[u].cor = PRETO;
   *tempo = (*tempo) + 1;
   V[u].f = *tempo;
}

//====Exe 2- componentes ===
void Busca_Profundidade (Grafo *G) {
   int u;
   int tempo = 0;
   //lista de vértices do grafo
   DFS *V = (DFS *)malloc(G->V * sizeof(DFS));

   //inicialização para o DFS
   for (u = 0; u < G->V; u++) {
      V[u].cor = BRANCO;
      V[u].pai = -1;
   }
   for (u = 0; u < G->V; u++) {
      if (V[u].cor == BRANCO) {
         printf("\nComponente: ");
         DFS_Visit (G, V, u, &tempo); 
      }
   }
   printf("Busca em profundidade:\n");
   for (u = 0; u < G->V; u++) {
      printf("%2d = [d : %2d, f : %2d, pai : %2d]\n", u, V[u].d, V[u].f, V[u].pai);
   }
}

// //
void DFS_Visit (Grafo *G, DFS *V, int u, int *tempo) {
   printf("\t %d", u);
   V[u].cor = CINZA;
   *tempo = (*tempo) + 1; 
   V[u].d = (*tempo);
   DFS *v;
   for (v = G->listaAdj[u]; v != NULL; v = v->proximo) {
      if (V[v->identificador].cor == BRANCO) {
         V[v->identificador].pai = u;
         DFS_Visit (G, V, v->identificador, tempo);
      }
   }
   V[u].cor = PRETO;
   *tempo = (*tempo) + 1;
   V[u].f = *tempo;
}

//Exe 3 - bipartido ===
void Busca_Profundidade (Grafo *G) {
   int u;
   int tempo = 0;
   //lista de vértices do grafo
   DFS *V = (DFS *)malloc(G->V * sizeof(DFS));

   //inicialização para o DFS
   for (u = 0; u < G->V; u++) {
      V[u].cor = BRANCO;
      V[u].pai = -1;
   }

    int pinta_cor = VERMELHO;

   for (u = 0; u < G->V; u++) {
      if (V[u].cor == BRANCO) {
         DFS_Visit (G, V, u, &tempo, pinta_cor); 
      }
   }

   printf("O grafo é bipartido\n");
 
}

// //
void DFS_Visit (Grafo *G, DFS *V, int u, int *tempo, int pinta_cor) {
   //V[u].cor = CINZA;
   V[u].cor = pinta_cor;
   *tempo = (*tempo) + 1; 
   V[u].d = (*tempo);
   DFS *v;
   for (v = G->listaAdj[u]; v != NULL; v = v->proximo) {
      //if (V[v->identificador].cor == BRANCO) {
      if (V[v->identificador].cor == pinta_cor) {
	 printf("O grafo não é bipartido!\n");
         exit(1);
      else if (V[v->identificador].cor == BRANCO) 	 
         V[v->identificador].pai = u;
         DFS_Visit (G, V, v->identificador, tempo, (pinta_cor == VERMELHO ? PRETO : VERMELHO));
      }
   }
   V[u].cor = PRETO;
   *tempo = (*tempo) + 1;
   V[u].f = *tempo;
}

*/