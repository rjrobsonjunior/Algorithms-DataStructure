#include "stack.h"

int main () {

    int tam = 6;
    Stack *s = create (tam);
    Stack *auxiliar = create(tam);
    int i;
    srand(time(NULL));

    /* gera os numeros aleatórios*/
    for(i = 0; i < tam; i++ ){
        push (s, rand()%10);
    }
    print (s);

    /*empilha os numeros impares da pilha s na pilha auxiliar*/
    while(!empty(s)){
        if(get_peek(s)%2 != 0){
            push( auxiliar, get_peek(s));
        }
        pop(s);
    }
    /*empilha os elementos da pilha auxiliar na pilha s para recuperar a ordem*/
    while(!empty(auxiliar)){
        push( s, get_peek(auxiliar));
        pop(auxiliar);
    }
    print (s);
    destroy (s);
    destroy (auxiliar);

    return 0;
}