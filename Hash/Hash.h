
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct hash
{
    int M;
    int N;
    Node** list;
} Hash;

Hash* CreateHash(int M);
void  InsertHash( Hash* H, int key); 
Node* SeachHash(Hash* H, int key);  

