/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
  Node* head;
  Node* current_item;
  Node* temp = nullptr;

  head = current_item;

  for (int i = 0; i < 6; i++)
  {
    current_item->value = i;
    temp = new Node;
    current_item->next = temp;
    current_item = current_item->next;
  }

  for (int i = 0; i < 6; i++)
  {
    cout << head->value << endl;
    head = head->next;
  }

  //Node* odds;
  //Node* evens;

  //split(head, odds, evens);

  /*
  while (odds)
  {
    cout << "odds: " << endl;
    cout << odds->value << endl;
    odds = odds->next;
  } */
}
