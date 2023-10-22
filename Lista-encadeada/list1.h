#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}List;

List* create();
List* insert_front(List* l, int elem);
void print(List* l);
List* remove(List *l, int elem);
void destroy(List *l);
