#include "utils.h"

/*Função para intercalar dois subvetores em um conjunto ordenado. 
 *{A} é o vetor de entrada, {l} é a esquerda (de left), 
 {m} é o meio (ou middle), {r} é a direita (de right),
 {O} é o vetor auxilar (de output). */
void merge (int A[], int l, int m, int r, int O[], int nivel) {
  /*Terminar*/	
  int i, j, k;
  for(i=l, j=m+1, k=l; (i <= m) && (j<= r); k++){
    if(A[i]<A[j]){
      O[k]=A[i++];
    }
    else{
      O[k]=A[j++];
    }
  }
  //descarrega
  while(i<=m){
    O[k++]=A[i++];
  }
  while(j<=r){
    O[k++]=A[j++];
  }

  for(i=0; i<nivel;i++){
  printf("  ");
}
  printf("Intercalando={");
  for(i=l; i<=r; i++){
    A[i]=O[i];
    printf(" %d,", O[i]);
  }
  printf("}; \n");
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r, int O[], int nivel) {
  /*Terminar*/	
  //int nivel
  if(l < r){
    int m = (l+r)/2;

    for(int i=0; i< nivel; i++){
      printf("  ");
    }
    printf("merge_sort(%d, %d, %d); \n" , l, m, r );
    merge_sort(A, l, m, O, nivel+1);
    merge_sort(A, m+1, r, O, nivel+1);
    merge(A, l, m, r, O, nivel+1);
}
}
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1, O, 0);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

