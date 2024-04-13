#include <vector>
#include <algorithm>
#include "Plane.h"
using namespace std;

/* Methods to implement
- empty() - returns true if the priority queue is empty and false otherwise.
• size() - returns the number of elements in the priority queue.
• push(Object o) - a void method which adds the object o to the priority queue. (Object can be
replaced with your own class.)
• pop() - removes and returns the first element of the priority queue.
• peek() - returns, but does not remove, the first element of the priority queue.
*/

class Queue {
  /*
    I implemented the priority queue using the C++ built in heap. I did this because it utilizes a
    max heap, since we are using ints to range each planes priority, those with the highest priority
    will bubble up to the top, and be removed using pop(), then the tree will reshuffle, bringing the next 
    plane to the top, this implementation also maximizes efficiency and readability of the class. I also have
    a class implementing the heap based queue from scratch as covered in class.

    - Tanner
  */

  private: 
    int size;
    vector<Plane> v;

  public:

    Queue() {}
    Queue(int s) : size(s) {}
    ~Queue() { v.empty(); size = 0; }
    bool empty() { return size == 0; }
    bool isEmpty() { return size == 0; }
    int size() { return size; }

    void push(Plane &p) {
        v.push_back(p);
        push_heap(v.begin(), v.end());
        size++;
    }

    Plane pop() {
        pop_heap(v.begin(), v.end());
        Plane p = v.back();
        v.pop_back();
        size--;
        return p;
    }

    Plane peek() {
        return v.front();
    }
    
};