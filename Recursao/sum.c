#include "list.h"

/* */
int sum (List *l) {
  /*Terminar.*/
  int soma;
  if(l != NULL){
    soma = l->data;
    return soma + sum(l->next);}
  else{return soma;}
}
/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
