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
#include <iostream>
#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  //Base cases: Empty head node
  if (in->value == 0)
  {
     odds->value = 0;
     evens->value = 0;
     
  }

  if(in->value % 2 == 0) //evens
  {
    evens->value = in->value; //sets the value for the current evens node
    evens = evens->next; //Moves to next node in evens
  }
  else //odds 
  {
    odds->value = in->value; //sets value for current odds node
    odds = odds->next; //moves to next node in odds
  }

  split(in->next,odds,evens); //recursive call.
  
}

/* If you needed a helper function, write it here */
