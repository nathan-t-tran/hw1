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
  cout << "test" << endl;

  Node* head = new Node(0, nullptr);
  Node* current_item;
  Node* temp = nullptr;

  current_item = head;

  for (int i = 1; i < 6; i++) 
  {
      current_item->next = new Node(i, nullptr);
      current_item = current_item->next;
  }

  for (int i = 0; i < 6; i++)
  {
    cout << head->value << endl;
    head = head->next;
  }

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(head, odds, evens);

  
  cout << "Evens list:" << endl;
  while (evens)
  {
      cout << evens->value << " ";
      evens = evens->next;
  }
  cout << endl;

  // Print the odds list
  cout << "Odds list:" << endl;
  while (odds)
  {
      cout << odds->value << " ";
      odds = odds->next;
  }
  cout << endl;
}
