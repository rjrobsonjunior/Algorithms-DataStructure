#include "Arvore.h"


Arvore* cria_arv_vazia (void) 
{
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) 
{
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) 
{
   return (a == NULL);
}

void arv_libera (Arvore* a) 
{
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}