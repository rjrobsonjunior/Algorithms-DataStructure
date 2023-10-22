#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node next;
} List;

List Insert(List *l, int elem);