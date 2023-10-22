#include "Arvore.h"

/*========= Exercício 1 - pré-ordem ====
pré-ordem(R, E, D): a, b, d, c, e, f
in-ordem(E, R, D): b, d, a, e, c, f
pós-ordem(E, D, R): d, b, e, f, c, a
*/

//========= Exercício 2 - pré-ordem ====
void PreOrdem(Arvore *a)
{
  if(a != NULL )
  {
    printf("%c \n", a->info);

    PreOrdem(a->esq);

    PreOrdem(a->dir);
    }
}

//========= Exercício 2 - in-ordem ====

void InOrdem(Arvore *a)
{
  if(a != NULL)
  {
    InOrdem(a->esq);

    printf("%c \n", a->info);

    InOrdem(a->dir);
  }
}
//========= Exercício 2 - pós-ordem ====
void PosOrdem(Arvore *a)
{
  if(a != NULL)
  {
    PosOrdem(a->esq);

    PosOrdem(a->dir);

    printf("%c \n", a->info);
}
}
//========= Exercício 3 - pertence ====
int pertence_arv (Arvore *a, char c)
{
  int esq, dir;
  if(a != NULL)
  {
    if(a->info == c)
    {
      return (1);
    }
    else
    {
      esq = pertence_arv(a->esq, c);
      dir = pertence_arv(a->dir, c);
      if(esq != 0 || dir != 0)
      {
        return (1);
      }
      else
      {
        return (0);
      }
    }
  }
  else
  {
    return 0;
  }
}

//========= Exercício 4 - conta nós ====
int conta_nos (Arvore *a)
{
  int n_nos = 1;
  if(a != NULL)
  {
    n_nos += conta_nos(a->esq);
    n_nos += conta_nos(a->dir);
  }
  else
  { 
    return 0;
  }
  return n_nos;
}
/*
int conta_nos(Arvore *a)
{
   if (!a)
      return 0;

   return (1 + conta_nos(a->esq) + conta_nos(a->dir));
}
*/

//========= Exercício 5 - calcula altura ====
int calcula_altura_arvore (Arvore *a)
{
  if( a != NULL)
  {
    int he = calcula_altura_arvore(a->esq);
    int hd = calcula_altura_arvore(a->dir);
    
    if( he > hd )
    {
      return he+1;
    }
    else
    {
      return hd+1;
    }
  }
  else
  {
    return -1;
  } 
}
//========= Exercício 6 - conta folhas ====
int conta_nos_folhas(Arvore *a)
{
  int folha = 1;
  if(a != NULL)
  {
    folha += conta_nos_folhas(a->esq);
    folha += conta_nos_folhas(a->dir);
  }
  else
  {
    return 0;
  }
  return folha;
}
/*
int countTreeLeaves(Tree* tree)
{
    if(isTreeEmpty(tree))
        return 0;
    
    if(isTreeEmpty(tree->left) && isTreeEmpty(tree->right))
        return 1;

    return(countTreeLeaves(tree->left) + countTreeLeaves(tree->right));
}
*/

int main (int argc, char *argv[]) {

  Arvore *a = constroi_arv ('a',
      constroi_arv('b',
      cria_arv_vazia(),
      constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
    ),
    constroi_arv('c',
      constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
      constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
    )
  );   
  //PreOrdem(a);
  //InOrdem(a);
  //PosOrdem(a);
  //printf("pertence: %d \n", pertence_arv(a, 'z'));
  //printf("numero de nos: %d\n", conta_nos(a));
  printf("altura da arvore é: %d\n", calcula_altura_arvore(a));
  //printf("numero de folhas da arvore é: %d\n", conta_nos_folhas(a));
  arv_libera (a);

  return 0;
}
