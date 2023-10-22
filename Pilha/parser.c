#include "stack.h"

int parser (char *c) {
  Stack *s = create(strlen(c));
  int elem;
  int i = 0;
  while (c[i] != '\0'){

    elem= get_peek(s);
    if(c[i] == 93 &&  elem == 91){
      pop(s);
    }
    else if(c[i] == 173 && elem == 175){
      pop(s);
    }
    else if(c[i] == 41 && elem == 40){
      pop(s);
    }
    else if(c[i] != 32){
      push(s, c[i]); 
    }   
    i++; 
  }
  print(s);
  return( empty(s) );
}

int main () {
  //char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  return 0;
}
