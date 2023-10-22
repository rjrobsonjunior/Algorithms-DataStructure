void swap(int* A, int i, int j)
{
  int t = A[i];
  A[i] = A[j];
  A[j] = t;
}

void print (int* A, int size)
{
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", A[i]);
   }
   printf("\n");
}

int Parent(int i)
{
    return ((i-1)/2);
}
int Left( int i)
{
    return (2*i + 1);
}

int Right(int i)
{
    return (2*i + 2);
}



void MaxHeapify( int* A, int size, int index)
{
    int left = Left(index);
    int right = Right(index);
    int bigger;
    //search bigger 
    if( left < size && A[left] > A[index])
    {
        bigger = left;
    }
    else
    {
        bigger = index;
    }
    if( right < size && A[right] > A[bigger])
    {
        bigger = right;
    }

    if(bigger != index)
    {
        swap(A, index, bigger);
        MaxHeapify(A, size, bigger);
    }
}

void BuildMaxHeap( int* A, int size)
{
    for(int i = (size/2) - 1 ; i >=0 ; i-- )
    {
        MaxHeapify(A, size, i);
    }
}

void HeapSort( int* A, int size)
{
    BuildMaxHeap(A, size);
    

    for(int i = size - 1; i >= 1; i--)
    {
        swap(A, 0, i);
        size = i;
        MaxHeapify(A, size, 0);
        print(A, 9);

    }
}

