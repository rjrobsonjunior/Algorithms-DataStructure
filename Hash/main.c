#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -99999

typedef struct _hash {
   int key;
} Hash;

int linear_probing (int chave, int iter, int M) {
    int position = ((chave % M )+iter)%M;
    return position;
}

int quadratic_probing (int chave, int iter, int M) {
    int position = ((chave % M )+(1*iter)+(3*iter*iter))%M;
    printf("position: %d \n", position);
    return position;
}

int double_hash (int chave, int iter, int M) {
   int position = chave % M + iter * (1 + chave % (M - 2));
   return position;
}

/* */
Hash* create_hash (int M) { 
   int h;
   Hash *H = (Hash *)malloc(M * sizeof(Hash));
   for (h = 0; h < M; h++) {
      H[h].key = EMPTY;
   }
   return H;
}

/* */
void free_hash (Hash *H, int M) {
   free(H);
}

/* */
int hash_search (Hash *H, int M, int key) {
   int j, i = 0;
   do {
      //j = linear_probing (key, i, M);
      j = quadratic_probing (key, i, M);
      //j = double_hash (key, i, M);
      printf("Testando chave: %d\n", j);
      if (H[j].key == key) {
         return j;
      }
      i++;
   } while ((i != M) || (H[j].key != EMPTY));
}

/* */
int hash_insert (Hash *H, int M, int key, int *colisoes) {
   int j, i = 0;
   do {
      j = linear_probing (key, i, M);
      //j = quadratic_probing (key, i, M);
      //j = double_hash (key, i, M);
      if (H[j].key == EMPTY) {
         H[j].key = key;
         printf("Testando chave: %d\n", j);
         return j;
      }
      else {
         *colisoes = *colisoes + 1;
      }
      i++;
   } while (i != M);
}

/* */
void hash_print (Hash *H, int M) {
   int i;
   for (i = 0; i < M; i++) {
      if (H[i].key != EMPTY) {
         printf("%2d - %d\n", i, H[i].key);
      }
      else {
         printf("%2d -   \n", i);
      } 
   }
}

int main () {
   int colisoes = 0;
   int M = 8;
   Hash *H = create_hash (M);
   hash_insert (H, M, 0, &colisoes);
   hash_insert (H, M, 1, &colisoes);
   hash_insert (H, M, 3, &colisoes);
   hash_insert (H, M, 8, &colisoes);
   hash_insert (H, M, 15, &colisoes);
   hash_insert (H, M, 24, &colisoes);
   hash_insert (H, M, 35, &colisoes);
   hash_insert (H, M, 48, &colisoes);

   printf("Número de colisões: %d\n", colisoes);
   hash_print (H, M);
   free_hash (H, M);
   return 0;
}