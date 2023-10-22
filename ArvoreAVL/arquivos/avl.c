#include "avl.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir) {
   return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura (Arvore* a) {
   /*TERMINAR!!!!*/
   return (a == NULL ? -1 : a->altura);
}

int atualizar_altura (Arvore *a) {
   if( a == NULL )
    {
      return -1;
    }
    else
    {
      int right = atualizar_altura(a->dir);
      int left = atualizar_altura(a->esq);
      a->altura = (right > left) ? (right + 1) : (left + 1);
      return a->altura;
   }
}
/*----------------------*/
int balanceamento (Arvore *a) {
   return ( altura(a->dir) - altura(a->esq) );
}

/*----------------------*/
Arvore* rotacao_simples_esq (Arvore* a) {
   No* t = a->dir;
   a->dir = t->esq;
   t->esq = a;
   a->altura = atualizar_altura(a);
   t->altura = atualizar_altura(t);

   return t;
}

/*----------------------*/
Arvore* rotacao_simples_dir (Arvore* a) {
   /*TERMINAR!!!!*/
   No* t = a->esq;
   a->esq = t->dir;
   t->dir = a;
   a->altura = atualizar_altura(a);
   t->altura = atualizar_altura(t);

   return t;
}

/*----------------------*/
Arvore* rotacao_dupla_esq (Arvore* a) {
   /*TERMINAR!!!!*/
   a->dir = rotacao_simples_dir(a->dir);
   return (rotacao_simples_esq(a));
}

/*----------------------*/
Arvore* rotacao_dupla_dir (Arvore* a) {
   /*TERMINAR!!!!*/
   a->dir = rotacao_simples_esq(a->esq);
   return (rotacao_simples_dir(a));

}

/*----------------------*/
Arvore* atualizar_fb_dir (Arvore *a) {
   /*TERMINAR!!!*/
   a->altura = atualizar_altura(a);
   if( balanceamento(a) == +2)
   {
      if( balanceamento(a->dir) >= 0)
      {
         a = rotacao_simples_esq(a); 
         printf("fb dir simples\n");

      }
      else
      {
         a = rotacao_dupla_esq(a);
         printf("fb dir dupla\n");
      }
   }
   return a;
}

/*----------------------*/
Arvore* atualizar_fb_esq (Arvore *a) {
   /*TERMINAR!!!*/
   a->altura = atualizar_altura(a);

   if( balanceamento(a) == -2)
   {
      if( balanceamento(a->esq) <= 0)
      {
         a = rotacao_simples_dir(a); 
         printf("fb esq simples\n");

      }
      else
      {
         a = rotacao_dupla_dir(a);
         printf("fb esq dupla\n");
      }
   }
   return a;
}

/*----------------------*/
Arvore* inserir (Arvore *a, char chave) {
   /*TERMINAR!!!*/
   if(a != NULL)
   {
      if(chave < a->chave)
      {
         a->esq = inserir(a->esq, chave);
         a = atualizar_fb_esq(a);
      }
      else
      {
         a->dir = inserir( a->dir, chave);
         a = atualizar_fb_dir(a);
      }
   }
   else
   {
      a = (No*)malloc(sizeof(No));
      a->chave = chave;
      a->esq = NULL;
      a->dir = NULL;
      a->altura = 0;
   }
   return a;
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore* remover (Arvore *a, char chave) {
   if (a == NULL) {
      return NULL;
   }
   else {
      if (chave < a->chave) {
         a->esq = remover (a->esq, chave);
         a = atualizar_fb_dir (a);
      }
      else if (chave > a->chave) {
         a->dir = remover (a->dir, chave);
         a = atualizar_fb_esq (a);
      }
      else {
         if ((a->esq == NULL) && (a->dir == NULL)) {
            free (a);
            a = NULL;
         }
         else if (a->esq == NULL) {
            No *tmp = a;
            a = a->dir;
            free (tmp);
         }
         else if (a->dir == NULL) {
            No *tmp = a;
            a = a->esq;
            free (tmp);
         }
         else {
            No *tmp = a->esq;
            while (tmp->dir != NULL) {
               tmp = tmp->dir;
            }
            a->chave = tmp->chave; 
            tmp->chave = chave;
            a->esq = remover (a->esq, chave); 
            a = atualizar_fb_dir (a);
         }
      }
      return a; 
   }   
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order (Arvore* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      printf("Chave: %c (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
      imprimir_in_order (a->esq, nivel + 1);
      imprimir_in_order (a->dir, nivel + 1);
   }
}