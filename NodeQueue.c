#include <stdlib.h>
#include "NodeQueue.h"

NodeQueue NodeQueueFactory() {

  NodeQueue queue = malloc(sizeof(NodeQueueStruct));
  queue->front = NULL;
  queue->rear = NULL;

  return queue;
}
