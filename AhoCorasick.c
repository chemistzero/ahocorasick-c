#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AhoCorasick.h"

Node buildTree(char* input[], int size) {

  Node root = NodeFactory();

  for(int i=0;i<size;i++) {

    Node current = root;

    for(int j=0;j<strlen(input[i]);j++) {

      // don't have this branch, create new
      if(current->next[(int) input[i][j]] == NULL) {
        Node newNode = NodeFactory();
        newNode->subString = input[i][j];
        newNode->parent = current;
        current->next[(int) input[i][j]] = newNode;
        current = newNode;
      }
      // share
      else {
        current = current->next[(int) input[i][j]];
      }

    }

    current->pattern = malloc(strlen(input[i]) + 1);
    strcpy(current->pattern, input[i]);

  }

  return root;
}

void buildFailPath(Node root) {

  NodeQueue queue = NodeQueueFactory();
  NodeQueueOperation queueOperation = NodeQueueOperationFactory();

  root->fail = root;

  // all node of level 2 's fail path is root.
  for(int i=0;i<128;i++) {

    if(root->next[i] != NULL) {

      for(int j=0;j<128;j++) {
        if(root->next[i]->next[j] != NULL) {
          queueOperation->enqueue(queue, root->next[i]->next[j]);
        }
      }
      root->next[i]->fail = root;
    }
  }

  while(queue->rear != NULL) {

    Node current = queueOperation->dequeue(queue);

    for(int j=0;j<128;j++) {
      if(current->next[j] != NULL) {
        queueOperation->enqueue(queue, current->next[j]);
      }
    }

    char subString = current->subString;
    Node parent = current->parent;

    while(1) {

      if(parent->fail->next[(int) subString] != NULL) {
        current->fail = parent->fail->next[(int) subString];
        break;
      }
      else {
        if(parent->fail == root) {
          current->fail = root;
          break;
        }
        else {
          parent = parent->fail->parent;
        }
      }

    }

  }

  free(queue);

}

MatchingResult search(Node root, char* content) {

  MatchingResult result = malloc(sizeof(MatchingResultStruct));
  result->next = NULL;
  MatchingResult head = result;

  Node current = root;

  int len = strlen(content), i = 0;
  while(i < len) {

    int position = content[i];

    if(current->next[position] != NULL) {

      current = current->next[position];
      if(current->pattern) {
        MatchingResult res = malloc(sizeof(MatchingResultStruct));
        res->start = i - strlen(current->pattern) + 2;
        res->end = i + 1;
        res->pattern = current->pattern;
        res->next = NULL;
        result->next = res;
        result = res;
        //printf(" - find %s at position %d\n", current->pattern, i - strlen(current->pattern) + 2);
      }
      i++;

    }
    else {

      if(current == root) {
        i++;
      }
      else {
        current = current->fail;
        if(current->pattern) {
          MatchingResult res = malloc(sizeof(MatchingResultStruct));
          res->start = i - strlen(current->pattern) + 1;
          res->end = i;
          res->pattern = current->pattern;
          res->next = NULL;
          result->next = res;
          result = res;
          //printf(" - find %s at position %d\n", current->pattern, i - strlen(current->pattern) + 1);
        }
      }

    }

  }

  while(current != root) {
    current = current->fail;
    if(current->pattern) {
      MatchingResult res = malloc(sizeof(MatchingResultStruct));
      res->start = i - strlen(current->pattern) + 1;
      res->end = i;
      res->pattern = current->pattern;
      res->next = NULL;
      result->next = res;
      result = res;
      //printf(" - find %s at position %d\n", current->pattern, i - strlen(current->pattern) + 1);
    }
  }

  return head;

}

void destroy(Node root) {

  if(!root) {
    return;
  }

  NodeQueue queue = NodeQueueFactory();
  NodeQueueOperation queueOperation = NodeQueueOperationFactory();

  Node current = NULL;
  queueOperation->enqueue(queue, root);
  root = NULL;
  while(queue->rear != NULL) {

    current = queueOperation->dequeue(queue);
    for(int i=0;i<128;i++) {
      if(current->next[i] != NULL) {
        queueOperation->enqueue(queue, current->next[i]);
      }
    }

    free(current);

  }

}

AhoCorasick AhoCorasickFactory() {
  AhoCorasick ahoCorasick = NULL;
  if(!ahoCorasick) {
    ahoCorasick = malloc(sizeof(AhoCorasickStruct));
    ahoCorasick->buildTree = buildTree;
    ahoCorasick->buildFailPath = buildFailPath;
    ahoCorasick->search = search;
    ahoCorasick->destroy = destroy;
  }
  return ahoCorasick;
}
