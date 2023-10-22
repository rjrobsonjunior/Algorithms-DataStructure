#include "queue.h"

void funcao (Queue *cabeca) {
    if (cabeca == NULL)
        return;
    funcao(cabeca->next);
    printf("%d ", cabeca->info);
  }
int main () {
  int i, n = 10;	
  Queue* l;
  l = create(n);
  for(int i=0; i< n; i++){
    enqueue(l,i);
  }
  print(l);
  funcao(l);
  return 0;
}

