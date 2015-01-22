#ifndef RAWOPERATION_H_INCLUDED
#define RAWOPERATION_H_INCLUDED

#include "Raw.h"

typedef struct {

  Raw (*readBytes)(const char*);
  void (*writeBytes)(const char*, Raw);
  int (*countLines)(const char*);
  char** (*readLines)(const char*, int);

} RawOperationStruct, * RawOperation;

Raw readBytes(const char*);

void writeBytes(const char*, Raw);

int countLines(const char*);

char** readLines(const char*, int);

RawOperation RawOperationFactory();

#endif // RAWOPERATION_H_INCLUDED
