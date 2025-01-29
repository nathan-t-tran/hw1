/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include "split.cpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  //cout << "test_split begin" << endl;

  Node* head = new Node(1, nullptr);
  Node* current_item;

  current_item = head;

  for (int i = 2; i <= 6; i++) 
  {
    current_item->next = new Node(i, nullptr);
    current_item = current_item->next;
  }


  //cout << "end of intializing" << endl;

  Node* odds = new Node(0, nullptr);
  Node* evens = new Node(0, nullptr);

  //cout << "calling split" << endl;
  split(head, odds, evens);
  //cout << "after split" << endl;

  cout << "odds: " << endl;
  while (odds)
  {
    cout << odds->value << endl;
    odds = odds->next;
  }

  cout << "evens: " << endl;
  while (evens)
  {
    cout << evens->value << endl;
    evens = evens->next;
  }

  Node* temp_head = head;
  cout << "printing list" << endl;

  while (temp_head)
  {
    cout << temp_head->value << endl;
    temp_head = temp_head->next;
  }
}
