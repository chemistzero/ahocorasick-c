#ifndef MATCHINGRESULT_H_INCLUDED
#define MATCHINGRESULT_H_INCLUDED

typedef struct MatchingResultStruct MatchingResultStruct, * MatchingResult;

struct MatchingResultStruct {
  int start;
  int end;
  char* pattern;
  MatchingResult next;
};

#endif // MATCHINGRESULT_H_INCLUDED
