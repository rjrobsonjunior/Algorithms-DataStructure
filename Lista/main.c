#include "queue.h"

int main(){

    int aleatorio, i;
    int size = 10;
    Queue *par, *impar;

    par = create(size);
    impar= create(size);

    while(!full(par) || !full(impar)){
        aleatorio= rand()%100 +1;
        if(aleatorio%2 == 0 && !full(par)){
            enqueue(par, aleatorio);
        }
        else if(!full(impar)){
            enqueue(impar, aleatorio);
        }
    }
    
    printf("fila par: ");
    print(par);
    printf("fila impar: ");
    print(impar);
    
    destroy(par);
    destroy(impar);
    return 0;
}
