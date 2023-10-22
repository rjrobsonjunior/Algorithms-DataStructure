#include "trie.h"

int main () {

  Trie *root = create_node ('\0');

  root = insert (root, "maria");
  root = insert (root, "mario");
  root = insert (root, "mar");
  root = insert (root, "marco");
  //root = insert (root, "marioca");
  //root = insert (root, "mosca");
  
  print(root, 0);
  delete (root, "mar");
  print(root, 0);
  delete (root, "maria");
  print(root, 0);
  delete (root, "mario");
  print(root, 0);
  delete (root, "marco");
  print(root, 0);
  
  
  //search (root, "marioca");
  //delete (root, "marioca");
  //search (root, "mosca");
  //delete (root, "mosca");
  //delete (root, "maria");
  //print (root, 0);

  return 0;
}
