#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct NodeStruct NodeStruct, * Node;

struct NodeStruct {
  Node* next;
  Node parent;
  Node fail;
  char subString;
  char* pattern;
};

Node NodeFactory();

#endif // NODE_H_INCLUDED
