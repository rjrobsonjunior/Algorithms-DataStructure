#include <time.h>
 
#include "Tree.h"

int main () {

    clock_t start, end;
    double elapsed_time;
    srand(time(NULL));

    SeachTree *t = makeSeachTree();
    /*
    t = Insert (t, 50);
    t = Insert (t, 30);
    t = Insert (t, 90);
    t = Insert (t, 20);
    t = Insert (t, 40);
    t = Insert (t, 95);
    t = Insert (t, 10);
    t = Insert (t, 35);
    t = Insert (t, 45);
    */
    for(int i = 0; i < 100000; i++)
    {
        t = Insert (t, i);
    }
    start = clock();
    Seach(t, -1);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Running time: %.6f\n", elapsed_time);
    //PreOrder(t);
    //printf("\n");
    //Remove(t, 40);
    //PreOrder(t);
    //printf("\n");
    //printf(" minimo: %d \n", Minimum(t));
    //printf(" maximo: %d \n", Maximum(t));
    //DecrescentPrint(t);
    //printf("\n");
    //printf(" Bigger branch: %d \n", BiggerBranch(t));
    TreeFre(t);

    return 0;
}