#include "list.h"

int in (List *l, int k){

    while(l != NULL){
        if(l->data == k){
            return 1;
        }
        l= l->next;
    }
    return 0;
}
int main(){

    List *l;
    l= create();
    l=insert(l, 5);
    l=insert(l, 7);
    l=insert(l, 9);
    l= insert(l, 0);
    if(in(l, 4))
        printf("elemento presente na lista \n");
    else
        printf("elemento não está prensente na lista \n");

    return 0;
}