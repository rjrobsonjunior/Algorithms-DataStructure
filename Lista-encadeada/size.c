#include "list.h"

int size(List* lista){
    int tam=0;
    while( lista != NULL){
        lista = lista->next;
        tam++;
    }
    return tam;
}
int main(){
    int tam;
    List* lista = create();
    for(int i=0; i<10; i++){
        tam= rand()%100;
        lista = insert(lista, tam);
    }
    tam = size(lista);
    print(lista);
    printf(" o tamanho da lista é %d", tam);

    return 0;
}