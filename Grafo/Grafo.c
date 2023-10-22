#include <stdio.h>
#include <stdlib.h>


/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de Edges. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de Edges. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

void PrintGrafoAdjacente(GrafoA* G, int size)
{
   printf("Grafo (lista adjacencia): \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d -> ", i);
        while(G->Adj[i] != NULL)
        {
            printf("%d ", G->Adj[i]->id);
            G->Adj[i]= G->Adj[i]->next;
        }
        printf("\n");
    }
}

void PrintGrafoMatriz(GrafoM* G, int size)
{
   printf("(matriz adjacencia): \n");
   printf("    0  1  2  3  4  5  \n");
   printf("    |  |  |  |  |  |  \n");
   for(int i = 0; i < size; i++)
   {
      printf("%d-  ", i);
      for(int j = 0; j < size; j++)
      {
         printf("%d  ", G->Mat[i][j]);
      }
      printf("\n");
   }
}


/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}


/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   return G;
}

void InsertEdgeListDirectional( GrafoA* GrafoA, int index, int data){

   //printf("ligação %d , %d \n", data1, data2);
   NoA* no1 = (NoA *)malloc( sizeof(NoA ));
   no1->id = data;
   no1->next = NULL;
   //inserindo no 2
   if(GrafoA->Adj[index] == NULL)
   {
      GrafoA->Adj[index] = no1;
   }
   else
   {
      NoA* noAux = GrafoA->Adj[index];
      while(noAux->next != NULL)
      {
         noAux = noAux->next;
         //printf("id: %d \n", noAux->id);
      }
      noAux->next = no1;
   } 
}

void InsertEdgeList( GrafoA* GrafoA, int data1, int data2){
   GrafoA->E += 1;
   InsertEdgeListDirectional( GrafoA, data1, data2);
   InsertEdgeListDirectional( GrafoA, data2, data1);     
}

void InsertEdgeMatriz( GrafoM* GrafoM, int data1, int data2)
{
   GrafoM->Mat[data1][data2] =1;
   GrafoM->Mat[data2][data1] =1;
}

void InitializeArray(GrafoM* Gm, int size )
{
   for(int i = 0; i < size; i++)
   {
      for(int j = 0; j < size; j++)
      {
         Gm->Mat[i][j] = 0;
      }
   }
}


/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}


/* */
int main () {

   int Va = 6; /*Número de vértices*/

   GrafoA* Ga = criar_grafo_adj (Va);
   InsertEdgeList( Ga, 0, 1);
   InsertEdgeList( Ga, 0, 2);
   InsertEdgeList( Ga, 0, 5);
   InsertEdgeList( Ga, 2, 1);
   InsertEdgeList( Ga, 3, 1);
   InsertEdgeList( Ga, 2, 3);
   InsertEdgeList( Ga, 3, 4);
   InsertEdgeList( Ga, 2, 4);
   InsertEdgeList( Ga, 5, 4);
   

   PrintGrafoAdjacente(Ga, Va);
   printf("n Edges: %d\n", Ga->E);

   int Vm = 6; /*Número de vértices*/


   GrafoM* Gm = criar_grafo_mat (Vm);
   InitializeArray(Gm, Vm );
   
   InsertEdgeMatriz( Gm, 0, 1);
   InsertEdgeMatriz( Gm, 0, 2);
   InsertEdgeMatriz( Gm, 0, 5);
   InsertEdgeMatriz( Gm, 2, 1);
   InsertEdgeMatriz( Gm, 3, 1);
   InsertEdgeMatriz( Gm, 2, 3);
   InsertEdgeMatriz( Gm, 3, 4);
   InsertEdgeMatriz( Gm, 2, 4);
   InsertEdgeMatriz( Gm, 5, 4);
   
   PrintGrafoMatriz(Gm, Vm);

   GrafoA* GaDir = criar_grafo_adj (Va);

   InsertEdgeListDirectional( GaDir, 0, 1);
   InsertEdgeListDirectional( GaDir, 0, 5);
   InsertEdgeListDirectional( GaDir, 1, 2);
   InsertEdgeListDirectional( GaDir, 1, 3);
   InsertEdgeListDirectional( GaDir, 2, 0);
   InsertEdgeListDirectional( GaDir, 2, 4);
   InsertEdgeListDirectional( GaDir, 3, 2);
   InsertEdgeListDirectional( GaDir, 4, 3);
   InsertEdgeListDirectional( GaDir, 5, 4);
   

   PrintGrafoAdjacente(GaDir, Va);

   


   liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);
   liberar_grafo_adj (GaDir);


   return 0;
}
