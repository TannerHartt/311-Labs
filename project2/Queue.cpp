#include <vector>
#include <algorithm>
#include "Plane.h"
using namespace std;


/*
- empty() - returns true if the priority queue is empty and false otherwise.
• size() - returns the number of elements in the priority queue.
• push(Object o) - a void method which adds the object o to the priority queue. (Object can be
replaced with your own class.)
• pop() - removes and returns the first element of the priority queue.
• peek() - returns, but does not remove, the first element of the priority queue.
*/

class Queue {
  private: 
    int size;
    vector<Plane> v;


  
  public:

    Queue() {}
    Queue(int s) : size(s) {}

    void empty() { size == 0; }
    bool isEmpty() { return size == 0; }
    int size() { return size; }

    void push(const Plane &p) {
        v.push_back(p);
        push_heap(v.begin(), v.end());
        size++;
    }

    void pop() {
        pop_heap(v.begin(), v.end());
        v.pop_back();
        size--;
    }

    Plane peek() {
        return v.front();
    }
    
};