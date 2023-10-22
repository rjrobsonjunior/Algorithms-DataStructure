#include  "list1.h"

List* create(){
    return NULL;
}

List* insert_front(List *l, int elem){
    List *new=(*List )malloc(sizeof(List));
    new->data= elem;
    new->next=l;
    return new;
}

void print(List* l){
    List *aux;
    for(aux = l; aux!= NULL; aux= aux->next){
        printf("Data %d ", aux->data);
    }
    printf("\n");
}  

List* remove(List *l, int elem){
    List *t= l, *p= NULL;

}
void destroy(List *l){
    while(l!= NULL){
        List *t= l->next;
        free(l);
        l = t;
    }
}