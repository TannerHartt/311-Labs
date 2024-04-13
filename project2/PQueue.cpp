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

        PQueue() {}
        PQueue(int s) : size(s) {}

        void push(Plane &plane) {
            heap.push_back(plane);
            size++;
            uwheapify(heap.size() - 1);
        }

        void insert(Plane &plane) {
            heap.push_back(plane);
            size++;
            uwheapify(heap.size() - 1);
            dwheapify(size - 1);
        }

        void pop() {
            if (!heap.empty()) {
                heap[0] = heap.back();
                heap.pop_back();
                size--;
                dwheapify(0);
            }
        }

        Plane peek() {
            if (!heap.empty()) {
                return heap[0];
            }
        }

        bool isEmpty() {
            return size == 0;
        }

        void clear() {
            heap.clear();
            size = 0;
        }

        int size() {
            return size;
        }
};