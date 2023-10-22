#ifndef TREEAVL_H
#define TREEAVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
   char data;
   int heigth;
   struct Tree *left;
   struct Tree *right;
} Tree;

int Bigger(int left, int right);
int Heightalculate(Tree* t);
int HeightSic(Tree* t);
int BalancingCalculate(Tree* t);
Tree* Insert( Tree* t, char d);
Tree* Remove(Tree* t, char d);
Tree* Balance(Tree* t);
Tree* RotationLeft( Tree* t);
Tree* RotationRight( Tree* t);
void PreOrder(Tree* t);


#endif
