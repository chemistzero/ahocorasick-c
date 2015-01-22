#ifndef QUEUEELEMENT_H_INCLUDED
#define QUEUEELEMENT_H_INCLUDED

#include "Node.h"

typedef struct QueueElementStruct QueueElementStruct, * QueueElement;

struct QueueElementStruct {
  Node data;
  QueueElement next;
};

#endif // QUEUEELEMENT_H_INCLUDED
