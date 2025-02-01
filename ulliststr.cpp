#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
 * Adds a new value to the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::push_back(const std::string& val)
{
  if (tail_ == NULL) //if list is empty
  {
    tail_ = new Item(); //creates new Item
    tail_->val[0] = val; //inserts val into new Item array
    tail_->last++; //increments the last
    head_ = tail_; //since empty list head and tail will be the same.
    size_++; //increases the size
  }
  else if (tail_->last == ARRSIZE) //no more space in the back to add val
  {
    Item* temp = tail_; //holds the old address of old tail_
    tail_ = new Item(); //creates a new tail_
    tail_->prev = temp; //connects new tail with the old tail
    temp->next = tail_; //connects old tail to new tail.
    tail_->val[0] = val; //adds val to the front of the new array
    tail_->last = 1; //updates last
    size_++; //increments size of linked list
  }
  else //there is space to add val
  {
    int back_index = tail_->last; //gets the index of the furthest back val in array
    tail_->val[back_index] = val; //adds the new val to the back of the array.
    tail_->last = back_index + 1; //updates last loc
    size_++; //increments size of linked list
  }
}

/**
 * Removes a value from the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_back()
{ 
  if (size() == 0)
  {
    return;
  }
  else if (tail_->last - tail_->first == 1) //checks if the the array currently only has one value
  {
    Item* temp = tail_; //holds tail, so that we can delete after some tasks.
    if (tail_ == head_) //this means that this is the only Item.
    { 
      tail_ = head_ = NULL; //resets the entire list as empty
      size_ = 0;
    }
    else
    {
      tail_ = tail_->prev;
      tail_->next = NULL;
      size_--;
    }
    delete temp;
  }
  else
  {
    //deletes the furthest back node.
    tail_->last--; 
    size_--;
  }
}

/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise, 
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val)
{
  if (head_ == NULL)
  {
    head_ = new Item(); //creates new Item
    head_->val[ARRSIZE - 1] = val; //sets the back of the array with val
    head_->first = ARRSIZE - 1; //updates first
    head_->last = ARRSIZE; //updates last
    tail_ = head_; //since empty
    size_++; //increases the size
  }
  else if (head_->first == 0) //no more room to add val
  {
    Item* temp = head_; //holds the address of the old head_
    head_ = new Item(); //creates a new item
    head_->next = temp; //connects new head with the old head
    temp->prev = head_; //connects old head to new head
    head_->val[ARRSIZE - 1] = val; //Sets value at the end of the new array
    head_->first = ARRSIZE - 1; //updates the new front val loc
    head_->last = ARRSIZE; //sets the last val external
    size_++; //increments size of linked list
  }
  else //there is room to add val
  {
    int front_index = head_->first; //grabs the index from the first 
    head_->val[front_index - 1] = val; //adds new val to front
    head_->first = front_index - 1; //updates the new front val loc
    size_++; //increments size of linked list
  }
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front()
{
  if (size() == 0)
  {
    return;
  }
  else if (head_->last - head_->first == 1) //checks if the the array currently only has one value
  {
    Item* temp = head_; //holds head, so we can delete after using.
    if (tail_ == head_) //this means that this is the only Item.
    {
      head_ = tail_ = NULL; //resets the entire list as empty
      size_ = 0;
    }
    else
    {
      head_ = head_->next;
      tail_->prev = NULL;
      size_--;
    }
    delete temp;
  }
  else
  {
    //deletes the furthest front node.
    head_->first--; 
    size_--;
  }
}

/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::back() const
{
  if (tail_->last == 0)
  {
    return tail_->val[0];
  }
  else
  {
    return tail_->val[tail_->last - 1];
  }

}

/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::front() const
{
  return head_->val[head_->first]; //gives the first element in the list
}

/** 
 * Returns a pointer to the item at index, loc,
 *  if loc is valid and NULL otherwise
 *   - MUST RUN in O(n) 
 */
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  bool debug = true;

  std::string* item_atLoc = NULL;

  if (loc >= size()) //if location is outside of the bounds of the array
  {
      return NULL;
  }   

  int array_index = head_->first; //keeps track of the inclusive array index
  Item* temp = head_; //walker that starts at head

  for (int list_index = 0; list_index < loc; list_index++)
  {
    if (debug)
    {
      std::cout << "current val: " << temp->val[array_index] << std::endl;
      std::cout << "array_index: " << array_index << std::endl;
      std::cout << "list_index: " << list_index << std::endl;
    }
    if (array_index == ARRSIZE - 1) //checks if the index has surpassed reached the arrsize.
    {
      temp = temp->next; //moves Item forward
      array_index = temp->first; //resets the index tracker
    }
    else
    {
      array_index++; //moves index forward
    }
  }

  item_atLoc = &temp->val[array_index]; //sets the return equal to what is found.

  return item_atLoc; 
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}



std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

