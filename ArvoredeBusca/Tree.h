#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
}SeachTree;

int Seach( SeachTree* t, int d);
SeachTree* Insert( SeachTree* t, int d);
SeachTree* Remove(SeachTree* t, int d);
int Minimum (SeachTree *t);
int Maximum (SeachTree *t);
void PreOrder( SeachTree* t);
void DecrescentPrint( SeachTree* t);
int BiggerBranch(SeachTree* t);
SeachTree* makeSeachTree (void);
void TreeFre (SeachTree* a); 