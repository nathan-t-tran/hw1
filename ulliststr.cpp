#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
  if (tail_->last == ARRSIZE) //no more space in the back to add val
  {
    Item* temp = tail_; //holds the old address of old tail_
    tail_ = new Item(); //creates a new tail_
    tail_->prev = temp; //connects new tail with the old tail
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
  if (head_->first == 0) //no more room to add val
  {
    Item* temp = head_; //holds the address of the old head_
    head_ = new Item(); //creates a new item
    head_->next = temp; //connects new head with the old head;
    head_->val[ARRSIZE - 1] = val; //Sets value at the end of the new array
    head_->first = ARRSIZE - 1; //updates the new front val loc
    head_->last = ARRSIZE; //sets the last val
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
  
}

/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1]; //returns back element of list
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
  std::string* item_atLoc = NULL;

  if (loc >= size()) //if location is outside of the bounds of the array
  {
      return NULL;
  }   

  int array_index = head_->first; //keeps track of the inclusive array index
  Item* temp = head_; //walker that starts at head

  for (int list_index = 0; list_index < loc; list_index++)
  {
    if (list_index == loc) //when they match!
    {
      item_atLoc = &temp->val[array_index]; //sets the return equal
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

