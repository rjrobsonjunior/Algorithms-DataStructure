#include "utils.h"
#include <stdio.h>
/* */
int* process_interval (int *A, int n, int range) {
  int i, j;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/
  //inicializa vetor C com 0 em todas posições
  for(i=0; i < range; i++){
    C[i]=0;
  }
  //indica a quantidade de recorrêcias de cada numero
  for(j= 0; j< n; j++ ){
    C[A[j]]+=1;
  }
  printf("C: {");
  for(i=0; i<range; i++){
    printf(" %d ,", C[i]);
  }
  printf("}\n");
  return C;
}

int query (int *C, int n, int i, int j) {
  /*Terminar*/
  int recurrence=0;
  for(int k =i-1; i<= j; i++){
    recurrence+=C[i];
}
  return recurrence;
}

/* */
int main () {
  int a, b, n = 15;
  int range = 10;
  int A[] = {9,2,0,8,7,9,3,2,0,7,5,0,2,6,0};
  print (A, n, "Input");
  int *C = process_interval (A, n, range);
  a = 0, b = 3;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 4, b = 8;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 0, b = 0;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 6, b = 6;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  return 0;
}

