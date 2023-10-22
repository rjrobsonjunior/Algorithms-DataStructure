#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* */
void fibonacciInterativo(int n) {
    unsigned long int a1 = 0;
    unsigned long int a2 = 1;
    unsigned long int soma;
    for (int i = 0; i < n; i++)
    {
        soma = a1 + a2;
        //printf("%i, ", soma);
        a1 = a2;
        a2 = soma;
    }
    printf("soma: %li \n ", soma);
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }

  int n = atoi(argv[1]);


  start = clock();
  fibonacciInterativo(n);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  return 0;
}