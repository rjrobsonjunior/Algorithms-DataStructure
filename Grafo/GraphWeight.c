#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noWeight {
   int id;          /*Identificador armazenado no nó. */
   int Weight;
   struct noWeight *next; /* Próximo nó na lista encadeada. */
} NoWeight;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct graphweight {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoWeight **Adj; /* Lista de adjacências. */
} GraphWeight;

void PrintGraphWeightdjacente(GraphWeight* G, int size)
{
   printf("Grafo (lista adjacencia): \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d -> ", i);
        while(G->Adj[i] != NULL)
        {
            printf("%d (w: %d) ", G->Adj[i]->id, G->Adj[i]->Weight);
            G->Adj[i]= G->Adj[i]->next;
        }
        printf("\n");
    }
}

GraphWeight* criar_grafo_adj_weight (int tamanho) {
   int v;
   GraphWeight *G = (GraphWeight *)malloc(sizeof(GraphWeight));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoWeight **)malloc(tamanho * sizeof(NoWeight *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GraphWeight *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

void InsertArestaListWeight( GraphWeight* GrafoA, int index, int data, int weight){

   GrafoA->E +=1;
   NoWeight* no1 = (NoWeight *)malloc( sizeof(NoWeight ));
   no1->id = data;
   no1->next = NULL;
   no1->Weight = weight;
   //inserindo no 2
   if(GrafoA->Adj[index] == NULL)
   {
      GrafoA->Adj[index] = no1;
   }
   else{
      NoWeight* NoWeightux = GrafoA->Adj[index];
      while(NoWeightux->next != NULL)
      {
         NoWeightux = NoWeightux->next;
      }
      NoWeightux->next = no1;
   } 
}


int main()
{
    int Va = 6; /*Número de vértices*/

    GraphWeight* Ga = criar_grafo_adj_weight (Va);

    InsertArestaListWeight( Ga, 0, 1, 1);
    InsertArestaListWeight( Ga, 0, 3, 5);
    InsertArestaListWeight( Ga, 1, 3, 8);
    InsertArestaListWeight( Ga, 2, 3, 4);
    InsertArestaListWeight( Ga, 2, 0, 5);
    InsertArestaListWeight( Ga, 3, 4, 3);
    InsertArestaListWeight( Ga, 3, 3, 6);
    InsertArestaListWeight( Ga, 4, 2, 7);
    InsertArestaListWeight( Ga, 4, 5, 9);
    InsertArestaListWeight( Ga, 5, 0, 2);


    PrintGraphWeightdjacente(Ga, Va);

    liberar_grafo_adj (Ga);

    return 0;
}