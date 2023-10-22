#include "utils.h"

/* */
void counting_sort (FILE *f, int range) {
  int i, j, total = 0;
  char letter;

  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/

  //inicializa vetor C com 0 em todas posições
  for(i=0; i < range; i++)
  {
    C[i]=0;
  }
  //indica a quantidade de recorrêcias de cada numero
  while((letter = fgetc(f)) !=EOF)
  {
    letter=tolower(letter);
    if(isalpha(letter)){
      letter=
      C[(int)letter-97]+=1;
      total++;
    }
  }

  printf("letras:       contagem:       frequência: \n");
  for(int i=0; i < range; i++){
    float freq= 100*(C[i]/total);
    printf(" %c:            %d                %f  \n", i+97 , C[i], freq);
  }
  /*Desalocando vetores auxiliares: */
  free (C);
  /*Imprimir no final desta função as frequências das letras!*/

}

/* */
int main (int argc, char *argv[]) {

  if (argc < 2) {
    printf("run: %s file.txt\n", argv[0]);
    exit(1);
  }

  FILE *f = fopen(argv[1], "r");

  int range = 25; /*número de letras do alfabeto (a-z)*/

  counting_sort (f, range);
  
  fclose (f);

  return 0;
}

