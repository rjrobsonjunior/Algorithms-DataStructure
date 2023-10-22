#include "recursao.h"

List Insert(List *l, int elem){
    if(l != NULL ){
        l->next= Insert(l->next, elem);
    }
    else{
        List *node= (*List)malloc(sizeof(List));
        l->data= elem;
        l->next= NULL;      
        return node;
    }
}
