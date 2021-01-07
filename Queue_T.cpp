// File: Queue_T.cpp
//
// Author: Mariano Augusto Jalif
// Course: CIS-221-82A
// Assignment: QUEUE
//
// I haven't neither shown nor copied code from/to anybody.
// I also state that I typed everything in this code on my own.
// I haven't watched anyone's code.
//
// Purpose: Implementation file for templatized queue class.
// This file includes method implementations for a Queue.

#ifndef QUEUE_T_CPP
#define QUEUE_T_CPP
#include "cassert"

#include "Queue_T.h"


/*****************************************************************************
 * Queue Method Implementations
 *****************************************************************************/
// Constructor.
// Postcondition: The queue has been initialized as an empty queue.
template < class T >
  Queue < T > ::Queue(size_t initial_capacity): data_(new T[initial_capacity]()), capacity_(initial_capacity), first_(0), last_(0), count_(0) {}

// Copy constructor.
// Postcondition: The queue has been initialized with the queue argument
//  passed in (i.e., same values, order, and number of elements).
template < class T >
  Queue < T > ::Queue(const Queue < T > & rhs)
//:   // Initialize data members here if needed.
{
  // Create data of the size of rhs.data
  // and then copy values of variables.
  data_ = new T[rhs.capacity_]();
  count_ = rhs.count_;
  capacity_ = rhs.capacity_;
  first_ = rhs.first_;
  last_ = rhs.last_;
  size_t index = first_;
  // Copy data from rhs.data to 
  // new queue object data.
  do {
    data_[index] = rhs.data_[index];
    index = next_index(index);
  } while (index != first_);
}

// Destructor
// Postcondition: Any allocated memory has been reclaimed/freed.
template < class T >
  Queue < T > ::~Queue(void) {
    delete[] data_;
  }

// Assignment operator.
// Postcondition: The queue has been assigned the queue argument
//  passed in (i.e., same values, order, and number of elements).
template < class T >
  Queue < T > &
  Queue < T > ::operator = (const Queue < T > & rhs) {
    if (this == & rhs) {
      return *this;
    }
    // Check if the capacities variables are equal,
    // if the are not, create an array of the rhs.capacity.
    if (capacity_ != rhs.capacity_) {
      T * newArray = new T[rhs.capacity_]();
      delete[] data_;
      data_ = newArray;
      capacity_ = rhs.capacity_;
    }
    // Copy values of variables.
    count_ = rhs.count_;
    first_ = rhs.first_;
    last_ = rhs.last_;
    size_t index = first_;
    // Copy data inside the rhs.data.
    do {
      data_[index] = rhs.data_[index];
      index = next_index(index);
    } while (index != first_);
    return *this;
  }

// Postcondition: A new copy of <new_item> is at the back of the queue.
template < class T >
  void
Queue < T > ::enqueue(const T & new_item) {
  // If count is equal capacity it needs to resize.
  if (count_ == capacity_) {
    // New capacity now has to be bigger. 
    size_t new_capacity = capacity_ + 5;
    T * new_queue = new T[new_capacity]();
    // Create indexes that are going iterate with
    // the old and new queue.
    size_t old_index = first_;
    size_t new_index = 0;
    do {
      new_queue[new_index] = data_[old_index];
      old_index = next_index(old_index);
      new_index++;
      // Copy elements until the index goes through the whole array.
      // making a whole round to it.
    } while (old_index != first_);
    // Delete old data and paste new queue
    delete[] data_;
    data_ = new_queue;
    // Now the capacity has a new value
    // and the first element is at the 
    // top of the array.
    capacity_ = new_capacity;
    first_ = 0;
    last_ = new_index - 1;
  }
  if (is_empty()) {
    // Reseting first and last just in case.
    first_ = 0;
    last_ = 0;
    data_[first_] = new_item;
  } else {
    last_ = next_index(last_);
    data_[last_] = new_item;
  }
  count_++;
}

// Precondition: size() > 0.
// Postcondition: The front item on the queue has been removed.  
//   Throws the <Underflow> exception if the queue is empty. 
template < class T >
  void
Queue < T > ::dequeue(void) {
  if (is_empty()) {
    throw Underflow();
  } else {
    // The data inside doesn't necessarily need
    // to be deleted as long as first and count 
    // are changed.
    first_ = next_index(first_);
    count_--;
  }
}

// Precondition: size() > 0.
// Postcondition: Returns the first queue item.
//   Throws the <Underflow> exception if the queue is empty. 
template < class T >
  T
Queue < T > ::first(void) const {
  if (is_empty()) {
    throw Underflow();
  } else {
    return data_[first_];
  }
}

// Postcondition: Returns true if the queue is empty, false otherwise. 
template < class T >
  bool
Queue < T > ::is_empty(void) const {
  return (count_ == 0);
}

// Postcondition: Returns the current number of elements in the queue.
template < class T >
  size_t
Queue < T > ::size(void) const {
  return count_;
}

// Postcondition: Returns true if the
//   size()'s of the two queues are equal and all the elements from 0
//   .. size()-1 are equal, else false.
template < class T >
  bool
Queue < T > ::operator == (const Queue < T > & rhs) const {
  // If have the same capacity and both are empty then they are equal.
  if (capacity_ == rhs.capacity_ && is_empty() && rhs.is_empty()) {
    return true;
  }
  // Comparing size and capacity.
  if (count_ == rhs.count_ && capacity_ == rhs.capacity_ &&
    first_ == rhs.first_ && last_ == rhs.last_) {
    size_t index = first_;
    // Comparing elements both arrays' elements.
    do {
      if (data_[index] != rhs.data_[index]) {
        return false;
      }
      index = next_index(index);
    } while (index != first_);
    return true;
  } else {
    return false;
  }
}

// Postcondition: Returns false if the
//   size()'s of the two queues are equal and all the elements from 0
//   .. size()-1 are equal, else true.
template < class T >
  bool
Queue < T > ::operator != (const Queue < T > & rhs) const {
  return (!( * this == rhs));
}

// Precondition: The parameter passed in is a valid index into the data
//  array.
// Postcondition: Returns the next index to use in the array.
template < class T >
  size_t
Queue < T > ::next_index(size_t index) const {
  assert(index <= capacity_);
  return (index + 1) % capacity_;
}

#endif /* QUEUE_T_CPP */