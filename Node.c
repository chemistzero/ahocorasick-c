#include <stdlib.h>
#include "Node.h"

Node NodeFactory() {

  Node node = malloc(sizeof(NodeStruct));

  node->next = malloc(sizeof(NodeStruct) * 128);
  for(int i=0;i<128;i++) {
    node->next[i] = NULL;
  }

  node->parent = NULL;
  node->fail = NULL;
  node->subString = 0;
  node->pattern = NULL;

  return node;
}
