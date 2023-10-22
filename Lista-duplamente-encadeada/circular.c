#include "list.h"

List* create_circular (List *head) {
  /*Terminar!*/	
  if(head != NULL){
    List *t = head;
    while(t->next != NULL){
      t= t->next;}
    t->next = head;
    head->prev = t;
    
  }
  return head;
}

int is_circular (List *l) {
  /*Terminar!*/	
}

int main () {
  int i;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  printf("Is circular: %d\n", is_circular(l));
  l = create_circular(l);
  printf("Is circular: %d\n", is_circular(l));
  return 0;
} 
