#ifndef SPLIT_H
#define SPLIT_H
#include <iostream>

struct Node 
{
  int value;
  Node* next;

  /**
   * Initializing constructor
   */
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }

  Node() //default constructor
  {
    value = 0;
    next = nullptr;
  }

};

void split(Node*& in, Node*& odds, Node*& evens);

#endif
