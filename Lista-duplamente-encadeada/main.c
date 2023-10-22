#include "list.h"

int main(){
    List *l = create();
    insert_front(l, 3);
    insert_front(l, 5);
    insert_front(l, 7);
    print(l);
    return 0;
}