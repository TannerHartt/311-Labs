#include <vector>
#include "Plane.h"
using namespace std;


class PQueue {
    private:
        vector<Plane> heap;
        int size;

        void uwheapify(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (heap[index] < heap[parent]) {
                    swap(heap[index], heap[parent]);
                    index = parent;
                }
                else break;
            }
        }

        void dwheapify(int index) {
            int size = heap.size();
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                dwheapify(smallest);
            }
        }



    public:

        PQueue();
        PQueue(int);

        void push(Plane&);
        void insert(Plane&);
        void pop();
        Plane peek();
        bool isEmpty();
        void clear();
        int size();

        void setSize(int s) {
            size = s;
        }
        int getSize() {
            return size;
        }
};