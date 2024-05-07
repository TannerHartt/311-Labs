#include "Graph.cpp"

class MinHeap {
    private:
        vector<Node*> heap;

        void heapifyDown(int i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < heap.size() && heap[left]->dist < heap[smallest]->dist)
                smallest = left;
            if (right < heap.size() && heap[right]->dist < heap[smallest]->dist)
                smallest = right;
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                heapifyDown(smallest);
            }
        }

        void heapifyUp(int i) {
            while (i != 0 && heap[(i - 1) / 2]->dist > heap[i]->dist) {
                swap(heap[i], heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }

    public:
        void insert(Node* n) {
            heap.push_back(n);
            heapifyUp(heap.size() - 1);
        }

        Node* pull() {
            if (heap.empty()) return nullptr;
            Node* top = heap.front();
            heap[0] = heap.back();
            heap.pop_back();
            if (!heap.empty()) heapifyDown(0);
            return top;
        }

        bool isEmpty() {
            return heap.empty();
        }

        int size() {
            return heap.size();
        }
};