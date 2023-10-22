#include "list.h"
#include <limits.h>

/* */
int position (List *l, int k) {
  /*Terminar*/

  if(l != NULL){
    if(  l->data == k){
      return 0;
    }
    else{ 
      int r = position(l->next, k);
      return (r != -1 ? r+1 : r); 
  }
  }
  else 
    return -1;
}

/* */
int main (){
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
  printf("Position of %d = %d\n", 9, position(l, 9));
  printf("Position of %d = %d\n", 10, position(l, 10));
  destroy (l);
  return 0;
}
