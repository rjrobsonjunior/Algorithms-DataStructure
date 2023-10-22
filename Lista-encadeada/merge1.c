#include "list.h"
/* */
List* merge (List *A, List *B) {
  /*Terminar*/	

	printf("Funncao merge\n");

	List* l;
	List* elem_a = A;
	List* elem_b = B;
	if (elem_a->data < elem_b->data) {
		l = elem_a;
		elem_a = elem_a->next;
	} 
    else {
		l = elem_b;
		elem_b = elem_b->next;
	}
	List* l_inicio = l;

	print(l_inicio);
	
	while (elem_a != NULL && elem_b != NULL) {
		
		if (elem_a->data < elem_b->data) {
			l->next = elem_a;
			l = elem_a;
			elem_a = elem_a->next;
		} 
		else {
			l->next = elem_b;
			l = elem_b;
			elem_b = elem_b->next;
		}
	}

	if (elem_a == NULL) {
		l_inicio->next = elem_a;
		}
	if (elem_b ==  NULL) {
		while (elem_a != NULL) {
			l_inicio->next = elem_b;
		}
	}
	return (l_inicio);
}

/* */
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}