#include "list.h"

int main(){
    List *l;
    l= create();
    l= insert_front(l, 0);
    l=insert_front(l, 2);
    l= insert_front(l, 7);
    print(l);
    return 0;
}