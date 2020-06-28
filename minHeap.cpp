#include<bits/stdc++.h>
#include "minHeap.h"
using namespace std;

MinHeap::MinHeap(int capacity){
    this->capacity = capacity;
    this->heap_size = 0;
    this->heap_arr = new int[capacity];
}

MinHeap::~MinHeap(){
    delete []heap_arr;
}

void swap(int& a, int&b){
    int temp = a;
    a = b;
    b = temp;
}

//Rearrange the array into a min heap recursively
void MinHeap::minHeapify(int i){
    int least = i; //root is set to least
    int left_child = left(i);
    int right_child = right(i);
    if(left_child<heap_size && heap_arr[left_child]<heap_arr[least]) least = left_child;
    if(right_child<heap_size && heap_arr[right_child]<heap_arr[least]) least = right_child; //check the least among root, left and right
    if(least!=i){ //if i root is not the least
        swap(heap_arr[least],heap_arr[i]); //swap root with the least
        minHeapify(least); //heapify the affected branch
    }
}

//Insert element k into heap
void MinHeap::insert(int k){
    if(capacity == heap_size){ //check if heap is full
        cout<<"\nOverflow: Maximum heap capacity reached.\n";
        return;
    }
    heap_size++; //if not full, increase heap size by 1
    int i = heap_size-1; //insert new element at last index i
    heap_arr[i] = k; //new element gets inserted at end
    while(i!=0 && heap_arr[parent(i)]>heap_arr[i]){ //check if new element is less than its parent
        swap(heap_arr[parent(i)],heap_arr[i]); //swap new element (lesser value) with its parent (having higher value)
        i=parent(i); //set i to the new position of new element and check again for heap constraints
    }
}

//Decrease the value of key to new_val at index i
void MinHeap::decreaseKey(int i, int new_val){
    heap_arr[i] = new_val;
    while(i!=0 && heap_arr[parent(i) > heap_arr[i]]){ //rearrange the heap to satisfy heap constraints
        swap(heap_arr[parent(i)], heap_arr[i]);
        i = parent(i);
    }
}

//Delete 1st element from min heap
int MinHeap::pop(){
    if(heap_size<=0) return INT_MAX; //if heap has no elements, return INT_MAX
    if(heap_size == 1){ //if heap has only 1 element, return that element and set heap size to 0
        heap_size--;
        return heap_arr[0];
    }
    //If heap has multiple elements
    int root = heap_arr[0]; //get the root element into a variable
    heap_arr[0] = heap_arr[heap_size-1]; //replace the 0th item with the last item in the heap
    heap_size--; //decrease heap size by 1 so that the next operation does not consider the entire heap
    minHeapify(0); //heapify the new heap minus last element
    return root; //return the least element
}

void MinHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN); //sets the value of index i to the lowest possible value, so that it bubbles up to the top of the heap
    pop(); //pop the element using previously defined function, so that it gets heapified after deletion
}