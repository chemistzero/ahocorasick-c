#ifndef NODEQUEUEOPERATION_H_INCLUDED
#define NODEQUEUEOPERATION_H_INCLUDED

#include "NodeQueue.h"

typedef struct {
  void (*enqueue)(NodeQueue, Node);
  Node (*dequeue)(NodeQueue);
} NodeQueueOperationStruct, * NodeQueueOperation;

void enqueue(NodeQueue, Node);

Node dequeue(NodeQueue);

NodeQueueOperation NodeQueueOperationFactory();

#endif // NODEQUEUEOPERATION_H_INCLUDED
