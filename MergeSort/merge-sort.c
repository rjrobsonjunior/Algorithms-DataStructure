#include "utils.h"

/*Função para intercalar dois subvetores em um conjunto ordenado. 
 *{A} é o vetor de entrada, {l} é a esquerda (de left), 
 {m} é o meio (ou middle), {r} é a direita (de right),
 {O} é o vetor auxilar (de output). */
void merge (float A[], int l, int m, int r, float O[]) {
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
  for(i=l; i<=r; i++){
    A[i]=O[i];
  }
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (float A[], int l, int r, float O[]) {
  if(l < r){
    int m = (l+r)/2;  
    merge_sort(A, l, m, O);
    merge_sort(A, m+1, r, O);
    merge(A, l, m, r, O);
}
}

/* */
int main (int argc, char *argv[]) {
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }
  float vector[20]= {4.68, 11.59, 7.32, 5.51, 9.59,	2.86,	10.01, 6.72, 8.39,	2.16,	2.38,	8.36, 7.97,	6.02,	5.05,	8.48, 2.35,	6.18,	12.85,	4.81};
  int i;
  int n = atoi(argv[1]);;
  float *A = (float *)malloc(n * sizeof(float));
  float *O = (float *)malloc(n * sizeof(float)); /*array auxiliar*/
  for (i = 0; i < 20; i++) {
    //A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i;   /*valores em ordem crescente*/
    //A[i] = n-i; /*valores em ordem descrescente*/
   A[i] = vector[i];   /*valores iguais*/
   printf("%f ", vector[i]);
  }
   printf("\n");
  start = clock();
  //print (A, n, "Input");
  merge_sort (vector, 0, 20-1, O);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  /*if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }*/
  for (i = 0; i < 20; i++) {
    //A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i;   /*valores em ordem crescente*/
    //A[i] = n-i; /*valores em ordem descrescente*/
   //A[i] = 0;   /*valores iguais*/
   printf("%f ", vector[i]);
  }
   printf("\n");
  free (A);
  free (O);
  return 0;
}

