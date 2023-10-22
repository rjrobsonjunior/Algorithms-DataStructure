#include <stdio.h>
#include <limits.h>

#include  "Heap.h"

int HeapExtractMax(int *A, int size)
{
    if( size < 1)
    {
        printf("erro: heap underflow");
    }
    int max = A[0];
    A[0] = A[size - 1];
    MaxHeapify(A, size, 0);
    
    return max;
}

void HeapIncreaseKey(int* A, int index, int key)
{
    if(key < A[index])
    {
        printf("erro: bigger key than the current one \n");
    }
    A[index]=key;

    for(int i = index; (i > 0) && (A[Parent(i)] < A[i]); Parent(i) )
    {
        swap(A, i, Parent(i));
    }
}

void MaxHeapInsert( int* A, int size, int key)
{
    A[size] = INT_MIN;
    HeapIncreaseKey(A, size-1, key);
}

int main () {

   int size = 12;

   int v[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

   print(v, size);

   /*Modificando a chave da posição 2 para o valor 1!*/   
   HeapIncreaseKey (v, 2, 16);
   
   printf ("After decrease-key: \n");
   print(v, size);

   return 0;
}



