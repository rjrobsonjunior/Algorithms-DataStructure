#include "Heap.c"
#include <stdio.h>

void swap(int* A, int i, int j);

void print(int* A, int size);

int Parent(int i );

int Left(int i );

int Right(int i );

void MaxHeapify( int* A, int size, int index);

void BuildMaxHeap(int* A, int size);

void HeapSort(int* A, int size);
