/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
#include <cstddef>
using namespace std;

/* Add a prototype for a helper function here if you need */
void deleteInput (Node*& in);

void split(Node*& in, Node*& odds, Node*& evens)
{

  if (in == NULL) //checks if the initial list is empty
  {
    deleteInput(in);
    return;
  }

  if (in->value % 2 == 0) //checks if even
  {
    evens = new Node (in->value, nullptr);
    split(in->next, odds, evens->next);
  }
  else //else it must be odd
  {
    odds = new Node (in->value, nullptr);
    split(in->next, odds->next, evens);
  }
}

/* If you needed a helper function, write it here */
void deleteInput (Node*& in)
{
  if (in == NULL)
  {
    return;
  }

  in = NULL;
  deleteInput(in->next);
}