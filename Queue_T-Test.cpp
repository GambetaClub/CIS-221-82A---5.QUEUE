// File: Queue_T-Test.cpp
//
// Author: Mariano Augusto Jalif
// Course: CIS-221-82A
// Assignment: QUEUE
//
// I haven't neither shown nor copied code from/to anybody.
// I also state that I typed everything in this code on my own.
// I haven't watched anyone's code.
//
//
// Purpose: Testing file for templatized queue class.

// Standard headers
#include <iostream>

#include <cstdlib>

#include "Queue_T.h"

// This typedef is useful if you want to queue characters.
typedef Queue < char > CQUEUE;

int
main(int argc, char * argv[]) {

  std::cout << "----------------~ 1 ~----------------" << std::endl << std::endl;

  // Test is empty function

  CQUEUE queue_1;

  std::cout << "Test is_empty function." << std::endl << std::endl;

  if (queue_1.is_empty()) {
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  } else {
    std::cout << "Test failed." << std::endl << std::endl;
  }

  std::cout << "----------------~ 2 ~----------------" << std::endl << std::endl;

  // Test dequeuing an element from an empty queue.

  std::cout << "Test dequeuing an element from an empty queue." << std::endl << std::endl;
  try {
    queue_1.dequeue();
  } catch (CQUEUE::Underflow) {
    std::cout << "Underflow caught" << std::endl;
    std::cout << "The program detected an Underflow Error which it was expected." << std::endl << std::endl;
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }

  std::cout << "----------------~ 3 ~----------------" << std::endl << std::endl;

  // Test queueing elements to a queue.

  std::cout << "Test queueing elements to a queue." << std::endl << std::endl;

  queue_1.enqueue('A');
  queue_1.enqueue('B');
  queue_1.enqueue('C');
  queue_1.enqueue('D');
  queue_1.enqueue('E');
  queue_1.enqueue('F');
  queue_1.enqueue('G');
  queue_1.enqueue('H');
  queue_1.enqueue('I');
  queue_1.enqueue('J');
  queue_1.enqueue('K');

  std::cout << "Test passed succesfully." << std::endl << std::endl;

  std::cout << "----------------~ 4 ~----------------" << std::endl << std::endl;

  // Test size function.

  std::cout << "Test size function." << std::endl << std::endl;

  if (queue_1.size() != 11) {
    std::cout << "Test failed." << std::endl;
  } else {
    std::cout << "Test passed succesfully" << std::endl << std::endl;
  }

  std::cout << "----------------~ 5 ~----------------" << std::endl << std::endl;

  // Test first function.

  std::cout << "Test first function." << std::endl << std::endl;

  if (queue_1.first() != 'A') {
    std::cout << "There is an error either with the first function or enqueue function." << std::endl;
    std::cout << "Test failed." << std::endl << std::endl;
  } else {
    std::cout << "The first function works correctly." << std::endl << std::endl;
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }

  std::cout << "----------------~ 6 ~----------------" << std::endl << std::endl;

  // Test dequeing elements from a queue.

  std::cout << "Test dequeing elements from a queue." << std::endl << std::endl;

  queue_1.dequeue();
  if (queue_1.first() != 'B') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'C') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'D') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'E') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'F') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'G') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'H') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'I') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'J') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'K') {
    std::cout << "There is an error with the order of the elements." << std::endl;
  } else {
    std::cout << "One element has succesfully stored" << std::endl;
  }
  queue_1.dequeue();

  std::cout << "Now the the program should detetect an empty queue, since it has been" << std::endl;
  std::cout << "enqueued and dequeued 10 items from the same queue." << std::endl << std::endl;
  std::cout << "QUEUE Count: " << queue_1.size() << std::endl << std::endl;
  if (queue_1.is_empty()) {
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  } else {
    std::cout << "Test failed." << std::endl << std::endl;
  }

  std::cout << "----------------~ 7 ~----------------" << std::endl << std::endl;

  // Test the copy constructor.

  std::cout << "Test copy constructor and compare queues' elements" << std::endl << std::endl;

  queue_1.enqueue('A');
  queue_1.enqueue('B');

  std::cout << "Something 1" << std::endl;

  CQUEUE queue_2(queue_1);

  std::cout << "QUEUE 1: Count: " << queue_1.size() << " - Element: " << queue_1.first() << std::endl;
  std::cout << "QUEUE 2: Count: " << queue_2.size() << " - Element: " << queue_2.first() << std::endl;

  if (queue_2.first() == queue_1.first()) {
    queue_2.dequeue();
    queue_1.dequeue();
    std::cout << "QUEUE 1: Size: " << queue_1.size() << " - Element: " << queue_1.first() << std::endl;
    std::cout << "QUEUE 2: Size: " << queue_2.size() << " - Element: " << queue_2.first() << std::endl << std::endl;
    if (queue_2.first() == queue_1.first()) {
      std::cout << "Test passed succesfully." << std::endl << std::endl;
    } else {
      std::cout << "The program detected an error with the copy constructor." << std::endl << std::endl;
      std::cout << "Test failed." << std::endl << std::endl;
    }
  } else {
    std::cout << "The program detected an error with the copy constructor." << std::endl << std::endl;
    std::cout << "Test failed." << std::endl << std::endl;
  }
  queue_1.dequeue();
  queue_2.dequeue();
  
  std::cout << "----------------~ 8 ~----------------" << std::endl << std::endl;

  // Test the assignment operator.

  std::cout << "Test the assignment operator and comparing both queues elements." << std::endl << std::endl;

  CQUEUE queue_17;

  queue_17.enqueue('M');
  queue_17.enqueue('J');

  CQUEUE queue_18 = queue_17;

  if (queue_17.first() == queue_18.first()) {
    queue_18.dequeue();
    queue_17.dequeue();
    if (queue_17.first() == queue_18.first()) {
      std::cout << "Test passed succesfully." << std::endl << std::endl;
    } else {
      std::cout << "The program detected an error with the copy constructor." << std::endl;
      std::cout << "Test failed." << std::endl << std::endl;
    }
  } else {
    std::cout << "The program detected an error with the copy constructor." << std::endl;
    std::cout << "Test failed." << std::endl << std::endl;
  }
  queue_18.dequeue();
  queue_17.dequeue();
  
  std::cout << "----------------~ 9 ~----------------" << std::endl << std::endl;

  // Test dequeuing all elements until we get an Underflow exception.

  std::cout << "Test dequeuing all elements until we get an Underflow exception." << std::endl;

  queue_1.enqueue('H');
  queue_1.enqueue('e');
  queue_1.enqueue('l');
  queue_1.enqueue('l');
  queue_1.enqueue('o');

  for (size_t i = 0; i <= 5; i++) {
    std::cout << "Size: " << queue_1.size() << std::endl;
    try {
      queue_1.dequeue();
    } catch (CQUEUE::Underflow) {
      std::cout << "Underflow caught" << std::endl;
      std::cout << "The program detected an Underflow Error which it was expected." << std::endl << std::endl;
      std::cout << "Test passed succesfully." << std::endl << std::endl;
    }
  }

  std::cout << "----------------~ 10 ~----------------" << std::endl << std::endl;

  // Test queues for being empty.

  std::cout << "Test queues for being empty." << std::endl << std::endl;

  if (queue_1.is_empty() && queue_17.is_empty()) {
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  } else {
    std::cout << "The program detected an error with the is_empty function" << std::endl;
    std::cout << "Test failed." << std::endl << std::endl;
  }

  std::cout << "----------------~ 11 ~----------------" << std::endl << std::endl;

  // Test enqueuing and dequeuing of elements.

  std::cout << "Test enqueuing and dequeuing of elements." << std::endl << std::endl;

  queue_1.enqueue('M');
  queue_1.enqueue('A');
  queue_1.enqueue('R');
  queue_1.enqueue('I');
  queue_1.enqueue('A');
  queue_1.enqueue('N');
  queue_1.enqueue('O');

  if (queue_1.first() != 'M') {
    std::cout << "The program detected an enqueue error." << std::endl;
  } else {
    std::cout << "The program dequeued the first element correcly." << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'A') {
    std::cout << "The program detected an enqueue error." << std::endl;
  } else {
    std::cout << "The program dequeued the second element correcly." << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'R') {
    std::cout << "The program detected an enqueue error." << std::endl;
  } else {
    std::cout << "The program dequeued the third element correcly." << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'I') {
    std::cout << "The program detected an enqueue error." << std::endl;
  } else {
    std::cout << "The program dequeued the fourth element correcly." << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'A') {
    std::cout << "The program detected an enqueue error." << std::endl;
  } else {
    std::cout << "The program dequeued the fifth element correcly." << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'N') {
    std::cout << "The program detected an enqueue error." << std::endl;
  } else {
    std::cout << "The program dequeued the sixth element correcly." << std::endl;
  }
  queue_1.dequeue();
  if (queue_1.first() != 'O') {
    std::cout << "The program detected an enqueue error." << std::endl;
  } else {
    std::cout << "The program dequeued the seventh element correcly." << std::endl << std::endl;
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }
  queue_1.dequeue();
  
  std::cout << "----------------~ 12 ~----------------" << std::endl << std::endl;

  // Test resizing of queue.

  std::cout << "Test resizing of queue." << std::endl << std::endl;

  CQUEUE queue_10;

  queue_10.enqueue('1');
  queue_10.enqueue('2');
  queue_10.enqueue('3');
  queue_10.enqueue('4');
  queue_10.enqueue('5');
  queue_10.enqueue('6');
  queue_10.enqueue('7');
  queue_10.enqueue('8');
  queue_10.enqueue('9');
  queue_10.enqueue('0');
  queue_10.enqueue('1');
  queue_10.enqueue('2');
  queue_10.enqueue('3');
  queue_10.enqueue('4');
  queue_10.enqueue('6');
  queue_10.enqueue('7');

  std::cout << "Test passsed succesfully." << std::endl << std::endl;

  std::cout << "----------------~ 13 ~----------------" << std::endl << std::endl;

  // Test next index function when last item is at the bottom of the array.

  std::cout << "Test next index function when last item is at the top of the array." << std::endl << std::endl;

  queue_1.enqueue('1');
  queue_1.enqueue('2');
  queue_1.enqueue('3');
  queue_1.enqueue('4');
  queue_1.enqueue('5');
  queue_1.enqueue('6');
  queue_1.enqueue('7');
  queue_1.enqueue('8');
  queue_1.enqueue('9');
  queue_1.enqueue('0');
  queue_1.dequeue();
  queue_1.enqueue('A');

  if (queue_1.first() != '2') {
    std::cout << "The program detected an error with the either the cursors" << std::endl;
    std::cout << "maintenance or next item function." << std::endl;
    std::cout << "Test failed." << std::endl << std::endl;
  }
  std::cout << "The program returned the first item succesfully." << std::endl << std::endl;
  std::cout << "Test passed succesfully." << std::endl << std::endl;

  std::cout << "----------------~ 14 ~----------------" << std::endl << std::endl;

  // Test equal operator.

  std::cout << "Test equal operator" << std::endl << std::endl;

  CQUEUE queue_3;

  if (queue_3 == queue_1) {
    std::cout << "Test failed." << std::endl << std::endl;
  } else {
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }

  std::cout << "----------------~ 15 ~----------------" << std::endl << std::endl;

  // Test equal operator.

  std::cout << "Test inequal operator" << std::endl << std::endl;

  if (!(queue_3 != queue_1)) {
    std::cout << "Test failed." << std::endl << std::endl;
  } else {
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }

  std::cout << "----------------~ 16 ~----------------" << std::endl << std::endl;

  // Test that two queues with same data but different capacity aren't equal.

  std::cout << "Test that two queues with same data but different capacity aren't equal.";
  std::cout << std::endl << std::endl;

  CQUEUE queue_4;
  CQUEUE queue_5; 

  queue_4.enqueue('1');
  queue_4.enqueue('2');
  queue_4.enqueue('3');
  queue_4.enqueue('4');
  queue_4.enqueue('5');
  queue_4.enqueue('6');
  queue_4.enqueue('7');
  queue_4.enqueue('8');
  queue_4.enqueue('9');
  queue_4.enqueue('0');
  queue_4.enqueue('1');
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();
  queue_4.dequeue();

  queue_4.enqueue('1');
  queue_4.enqueue('2');
  queue_4.enqueue('3');

  queue_5.enqueue('1');
  queue_5.enqueue('2');
  queue_5.enqueue('3');

  std::cout << "Checking that both have the same data." << std::endl;

  std::cout << "QUEUE 1: Count: " << queue_4.size() << " - Element: " << queue_4.first() << std::endl;
  std::cout << "QUEUE 2: Count: " << queue_5.size() << " - Element: " << queue_5.first() << std::endl;
  
  queue_4.dequeue();
  queue_5.dequeue();
  
  std::cout << "QUEUE 1: Count: " << queue_4.size() << " - Element: " << queue_4.first() << std::endl;
  std::cout << "QUEUE 2: Count: " << queue_5.size() << " - Element: " << queue_5.first() << std::endl;

  queue_4.dequeue();
  queue_5.dequeue();

  std::cout << "QUEUE 1: Count: " << queue_4.size() << " - Element: " << queue_4.first() << std::endl;
  std::cout << "QUEUE 2: Count: " << queue_5.size() << " - Element: " << queue_5.first() << std::endl << std::endl;

  if(queue_4 != queue_5){
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }else
  {
    std::cout << "Test failed." << std::endl << std::endl;
  }

  queue_4.dequeue();
  queue_5.dequeue();

  std::cout << "----------------~ 17 ~----------------" << std::endl << std::endl;

  // Test that copy constructor creates an array of same capacity.

  std::cout <<"Test that copy constructor creates an array of same capacity."<< std::endl << std::endl;

  queue_4.enqueue('1');
  queue_4.enqueue('2');
  queue_4.enqueue('3');

  CQUEUE queue_11(queue_4);

  std::cout << "Checking that both have the same data." << std::endl;

  std::cout << "QUEUE 1: Count: " << queue_4.size() << " - Element: " << queue_4.first() << std::endl;
  std::cout << "QUEUE 2: Count: " << queue_11.size() << " - Element: " << queue_11.first() << std::endl;
  
  queue_4.dequeue();
  queue_11.dequeue();
  
  std::cout << "QUEUE 1: Count: " << queue_4.size() << " - Element: " << queue_4.first() << std::endl;
  std::cout << "QUEUE 2: Count: " << queue_11.size() << " - Element: " << queue_11.first() << std::endl;

  queue_4.dequeue();
  queue_11.dequeue();

  std::cout << "QUEUE 1: Count: " << queue_4.size() << " - Element: " << queue_4.first() << std::endl;
  std::cout << "QUEUE 2: Count: " << queue_11.size() << " - Element: " << queue_11.first() << std::endl << std::endl;

  if(queue_4 == queue_11){
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }else
  {
    std::cout << "Test failed." << std::endl << std::endl;
  }

  queue_4.dequeue();
  queue_11.dequeue();

  std::cout << "----------------~ 18 ~----------------" << std::endl << std::endl;

  // Test that checks if two empty arrays with different capacities aren't equal.

  std::cout << "Test that checks if two empty arrays with different capacities aren't equal.";
  std::cout << std::endl << std::endl;

  CQUEUE queue_6(3);

  if(queue_6 != queue_4){
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }else
  {
    std::cout << "Test failed." << std::endl << std::endl;
  }

  std::cout << "----------------~ 19 ~----------------" << std::endl << std::endl;

  // Test that queues with same arrays but with different first and last aren't equal.

  std::cout << "Test that queues with same arrays but with different first and last aren't equal.";
  std::cout << std::endl << std::endl;

  CQUEUE queue_7(3);

  queue_6.enqueue('D');
  queue_6.enqueue('B');
  queue_6.enqueue('C');

  queue_7.enqueue('A');
  queue_7.enqueue('B');
  queue_7.enqueue('C');
  queue_7.dequeue();
  queue_7.enqueue('D');

  std::cout << "The queues created here have exactly the same array; however," << std::endl;
  std::cout << "they are not the same queue because of their first and last." << std::endl << std::endl;

  if(queue_6 != queue_7){
    std::cout << "Test passed succesfully." << std::endl << std::endl;
  }else
  {
    std::cout << "Test failed." << std::endl << std::endl;
  }

  std::cout << "----------------~ END ~----------------" << std::endl << std::endl;
  
  return EXIT_SUCCESS;

}