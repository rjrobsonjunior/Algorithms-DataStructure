#include "TreeAVL.h"

int main () {

   Tree *AVL = NULL;

   AVL = Insert(AVL, 'Q');
   /*TERMINAR (INSERIR DEMAIS CHAVES)!!!*/

   //AVL = remover (AVL, 'A');
   //AVL = remover (AVL, 'H');
   //AVL = remover (AVL, 'E');
   //AVL = remover (AVL, 'W');
   //AVL = remover (AVL, 'G');
   //AVL = remover (AVL, 'N');
   //AVL = remover (AVL, 'P');
   //AVL = remover (AVL, 'O');

   imprimir_in_order (AVL, 0);

   return 0;
}