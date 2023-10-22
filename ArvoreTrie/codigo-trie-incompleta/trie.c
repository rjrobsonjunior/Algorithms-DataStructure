#include "trie.h"

/* */
Trie *create_node (char data) {
  Trie *node = (Trie *)malloc(sizeof(Trie));
  node->data = data;
  node->end = FALSE;
  node->nchild = 0;
  int i;
  //size is the alphabet size 
  for (i = 0; i < size; i++) {
    node->keys[i] = NULL;	   
  }
  return node;   
}

/* */
void free_node (Trie *node) {
  int i;
  for (i = 0; i < size; i++) {
    if (node->keys[i] != NULL) {
      free_node (node->keys[i]);	    
    }
  }	  
  free (node);
}

/* */
Trie *insert (Trie *root, char *word) {
  if(search_auxiliary(root, word))
  {
    printf("Arvore já inserida \n");
  }
  else
  {
    Trie* t = root;
    for(int i = 0; word[i] != '\0'; i++)
    {
      int index = word[i]-'a';
      if(t->keys[index] == NULL)
      {
        t->keys[index]=create_node(word[i]);
      }
      t->nchild ++;
      t= t->keys[index];
    }
    t->end = TRUE;
  }

  return root;  	
}

/* */
int search_auxiliary (Trie *root, char *word) {
  Trie* t = root;
  for(int i = 0; word[i] != '\0'; i++)
  {
    int index = word[i] - 'a' ;
    if(t->keys[index] == NULL)
    {
      return FALSE;
    }
    else
    {
      t = t->keys[index];
    }
  }
  if(t->end)
  {
    return TRUE;
  }
  return FALSE; 
}

void search (Trie *root, char *word) {
  if (search_auxiliary (root, word))
    printf("Word %s found!\n", word);
  else  
    printf("Error: word %s not found!\n", word);
}

/* */
void print (Trie *root, int level) {
  if (root != NULL) {
    int i;
    if (root->data == '\0')
      printf ("(null)");	    
    for (i = 0; i < level; i++) {
      printf ("| ");
    }	    
    printf ("%c (%d - %d)\n", root->data, root->end, root->nchild);
    for (i = 0; i < size; i++) {
      print (root->keys[i], level+1);      
    }
  }	  
}

void delete (Trie *root, char *word) 
{
  if(search_auxiliary(root, word))
  {
    Trie* t = root;
    for(int i = 0; (word[i] != '\0') && (t!= NULL); i++)
    {
      t->nchild--;
      int index = word[i]-'a';
      Trie* t_auxiliary = t->keys[index];
      if((t_auxiliary->nchild <= 1) && (t->end == FALSE))
      {
        free_node(t_auxiliary);
        t->keys[index] = NULL;
      }
      if(t)
      {
        t = t->keys[index];
      }
    }
    if(t)
    {
      t->end = FALSE; 
    }
  }
  else
  {
    printf(" NOT DELETED, NOT FOUND WORD \n");
  }
} 

/*

void delete(Trie *root, char *word)
{

  if(search_auxiliary(root, word))
  {
    Trie *t = root;
    for (int i = 0; word[i] != '\0' && t != NULL; i++)
    {
      //printf("AAA\n");
      int index = word[i] - 'a';
      --(t->nchild);
      if (!(t->nchild))
      {
        //printf("BBB\n");
        Trie *h = t->keys[index];
        if(h)
        {

        t->keys[index] = NULL;
        free_node(h);//recursiva
        }
      }
      t=t->keys[index];
    }
    if(t!=NULL){t->end=FALSE;}

  }

  else{printf("ERROR: the word %s is not a key \n",word);}
  */

