#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap{
    private:
        int* heap_arr;
        int capacity;
        int heap_size;
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void minHeapify(int i);
        int size() {return this->heap_size;};
        void insert(int k);
        void deleteKey(int i);
        void decreaseKey(int i, int new_val);
        int pop();
        int getMin() {return heap_arr[0];};
        int parent(int i) {return heap_arr[(i-1/2)];};
        int left(int i) {return heap_arr[2*i+1];};
        int right(int i) {return heap_arr[2*i+2];};
};

void swap(int& a, int&b);

#endif