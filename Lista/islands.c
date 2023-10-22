#include "pqueue.h"

int inside (int i, int j, int n) {
  if ((i < 0) || (j < 0) || (i >= n) || (j >= n))
    return 0;
  return 1;    
}

void print_matrix (char M[][10], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%c ", M[i][j]);
    }
    printf("\n");
  }   
}

void conquer (char M[][10], int i, int j, int n, int nlabel) {
  Queue *q = create((n*n)+1); /*supondo pior caso*/
  enqueue (q, (point){i,j});
  M[i][j] = '0' + (char) nlabel;
  while (!empty(q)) {
    point p = dequeue (q);
    // vetor que armazena as cordenadas das posições vizinhas
    point vizinhas[8];
    vizinhas[0].y = p.y-1;
    vizinhas[0].x = p.x;

    vizinhas[1].y = p.y+1;
    vizinhas[1].x = p.x;

    vizinhas[2].y = p.y;
    vizinhas[2].x = p.x-1;
    
    vizinhas[3].y = p.y;
    vizinhas[3].x = p.x+1;

    vizinhas[4].y = p.y-1;
    vizinhas[4].x = p.x-1;

    vizinhas[5].y = p.y-1;
    vizinhas[5].x = p.x+1;

    vizinhas[6].y = p.y+1;
    vizinhas[6].x = p.x-1;

    vizinhas[7].y = p.y+1;
    vizinhas[7].x = p.x+1;

    for(int k = 0; k < 8; k++)
    {
      if(inside(vizinhas[k].x, vizinhas[k].y, n) && M[vizinhas[k].x][vizinhas[k].y] == '*')
      {
          enqueue(q, vizinhas[k]);
          M[vizinhas[k].x][vizinhas[k].y] = '0' + (char) nlabel;
      }
    }
  }
  destroy (q); 
}

int count_islands (char M[][10], int n) {
  int i, j, sum = 0;	
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (M[i][j] == '*') {
	      sum++;
        conquer (M, i, j, n, sum);     
      }	      
    }	     
  }
  return sum;
}

int main () {

  int n = 10;

  char M[][10] = 
    { {'*',' ','*',' ',' ',' ','*','*','*','*'}, 
      {' ',' ','*',' ','*',' ','*',' ',' ',' '},	    
      {'*','*','*','*',' ',' ','*',' ',' ',' '},
      {'*',' ',' ','*',' ',' ',' ',' ',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'},
      {' ','*',' ','*',' ',' ','*','*','*','*'},
      {' ',' ',' ',' ',' ','*','*','*',' ',' '},
      {' ',' ',' ','*',' ',' ','*','*','*',' '},
      {'*',' ','*',' ','*',' ',' ','*',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'} 
    } ;

  print_matrix (M, n);
  printf("Número de ilhas: %d\n", count_islands (M, n));
  print_matrix (M, n);

  return 0; 
}

