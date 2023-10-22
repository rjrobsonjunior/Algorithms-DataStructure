#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* */
int fibonacciRecursivo(int n) {
  if( n <= 1 )
  {
    return 1;
  }
  else 
  {
    int soma = fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    //printf("%i ", soma);
    return soma;
  }
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
  int i = fibonacciRecursivo(n);
  printf("%i, ", i);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  return 0;
}