/* 
queue.cpp

Author: Samuel Lee

Short description of this file:
*/

#include "queue.h"

// constructor. maxlen must be as large as the total number
// of Locations that will ever be entered into this Queue.
// this is complete, you don't need to change it.
Queue::Queue(int maxlen) {
   contents = new Location[maxlen];
   head = 0;
   tail = 0;
}

// destructor. releases resources. C++ will call it automatically.
// this is complete, you don't need to change it.
Queue::~Queue() {
   delete[] contents;
}

// insert a new Location at the end/back of our list   
void Queue::push(Location loc) {
   // FILL THIS IN

	contents[tail] = loc; //put new location in
	tail++; //update index

}

// return and "remove" the oldest Location not already extracted
Location Queue::pop() {
   // FILL THIS IN
   
   Location old_loc = contents[head]; //set old head equal to a variable
   head++; //update index of head
   return old_loc; 
}

// is this Queue empty? (did we extract everything added?)
bool Queue::is_empty() {
   // FILL THIS IN

	bool empty = false; //initialize

	if (head == tail) //if head reaches tail
	{
		empty = true; //queue is empty
	}

	return empty;
}

