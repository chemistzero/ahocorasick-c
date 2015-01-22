#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define Max 65536
#include "QueueElement.h"

typedef struct {

  QueueElement front;
  QueueElement rear;

} NodeQueueStruct, * NodeQueue;

NodeQueue NodeQueueFactory();

#endif // QUEUE_H_INCLUDED
