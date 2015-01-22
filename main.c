#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "AhoCorasick.h"
#include "RawOperation.h"
#include "MatchingResult.h"

int main(int argc, const char* argv[]) {

  char** pattern;
  int numberOfPattern;
  char* content;

  if(argc != 3) {
    printf("# of arguments should be 2.\n");
    printf("usage: ./a.out patternFile payloadFile\n");
    return 0;
  }

  RawOperation rawOperation = RawOperationFactory();

  printf("\n - Reading pattern file ...\n\n");

  numberOfPattern = rawOperation->countLines(argv[1]);

  printf(" - Total %d patterns:\n", numberOfPattern);

  pattern = rawOperation->readLines(argv[1], numberOfPattern);

  printf(" - Reading pattern file succeed.\n\n");

  for(int i=0;i<numberOfPattern;i++) {
    printf("   - %s\n", pattern[i]);
  }

  printf("\n - Reading content file ...\n\n");

  Raw raw = rawOperation->readBytes(argv[2]);
  content = raw->data;

  printf(" - Reading content file succeed.\n\n");
  printf(" - Content:\n");
  printf("   - %s\n\n", content);

  AhoCorasick ahoCorasick = AhoCorasickFactory();
  Node root = ahoCorasick->buildTree(pattern, numberOfPattern);
  ahoCorasick->buildFailPath(root);
  MatchingResult res = ahoCorasick->search(root, content);

  if(!res->next) printf(" - no result!\n");
  else {
    while(res->next) {
      printf(" - find %s at position %d ~ %d\n", res->next->pattern, res->next->start, res->next->end);
      MatchingResult temp = res;
      res = res->next;
      free(temp);
    }
  }

  free(raw);
  ahoCorasick->destroy(root);

  return 0;
}
