#include "list.h"

/* */
List* merge (List *A, List *B){

  List *C;
  //cópias das listas para não alterar os laços originais
  List *A_aux = A;
  List *B_aux = B;

  //armazena a semente da lista encadeada
  if( A_aux->data < B_aux->data){
    C = A_aux;
    A_aux = A_aux->next;
  }
  else{
    C = B_aux;
    B_aux = B_aux->next;
  }
  List *C_aux = C;
  // loops para salvar o endereço de cada laço
  while( A_aux != NULL && B_aux != NULL){
    if( A_aux->data < B_aux->data ) {
      C->next = A_aux;
      C = A_aux;
      A_aux= A_aux->next;
      }
    else {
      C->next = B_aux;
      C = B_aux;
      B_aux = B_aux->next;
    }
    printf("c");
    print(C_aux);
  }
  if(A_aux == NULL){
    while(B_aux != NULL){
      C->next = B_aux;
      C = B_aux;
      B_aux = B_aux->next;
      printf("c");
      print(C_aux);
    }
  }
  else if( B_aux == NULL){
    while(A_aux != NULL){
      C->next = A_aux;
      C = A_aux;
      A_aux= A_aux->next;
      printf("c");
      print(C_aux);
    }
  }
  return ( C_aux );
 
}

/* */
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}
