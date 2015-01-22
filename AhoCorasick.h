#ifndef AHOCORASICK_H_INCLUDED
#define AHOCORASICK_H_INCLUDED

#include "Node.h"
#include "NodeQueue.h"
#include "NodeQueueOperation.h"
#include "MatchingResult.h"

typedef struct {

  Node (*buildTree)(char* [], int);
  void (*buildFailPath)(Node);
  MatchingResult (*search)(Node, char*);
  void (*destroy)(Node);

} AhoCorasickStruct, * AhoCorasick;

Node buildTree(char* [], int);

void buildFailPath(Node);

MatchingResult search(Node, char*);

void destroy(Node);

AhoCorasick AhoCorasickFactory();

#endif // AHOCORASICK_H_INCLUDED
