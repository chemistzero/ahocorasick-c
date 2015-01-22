#include <stdlib.h>
#include "NodeQueueOperation.h"

void enqueue(NodeQueue queue, Node node) {

  QueueElement element = malloc(sizeof(QueueElementStruct));
  element->data = node;
  element->next = NULL;

  // first enqueue
  if(queue->rear == NULL) {
    queue->front = element;
  }
  else queue->rear->next = element;
  queue->rear = element;
}

Node dequeue(NodeQueue queue) {
  if(queue->front != NULL) {
    // last queue element
    if(queue->front == queue->rear) {
      queue->rear = NULL;
    }
    QueueElement element = queue->front;
    queue->front = queue->front->next;
    Node node = element->data;
    free(element);
    return node;
  }
  else return NULL;
}

NodeQueueOperation NodeQueueOperationFactory()  {
  NodeQueueOperation nodeQueueOperation = NULL;
  if(!nodeQueueOperation) {
    nodeQueueOperation = malloc(sizeof(NodeQueueOperationStruct));
    nodeQueueOperation->enqueue = enqueue;
    nodeQueueOperation->dequeue = dequeue;
  }
  return nodeQueueOperation;
}


