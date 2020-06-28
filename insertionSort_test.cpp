#include<bits/stdc++.h>
using namespace std;

void print_arr(int* arr,size_t n){
    for(size_t i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//In insertion sort, we pick the value of 1 index and compare it with all values to the left of that index
//if no element to the left is higher than the value, we set the value at that index and move to the next one
//All elements are shifted to the right by one step with each iteration if conditions are met

void insertionSort(int* arr, size_t n){
    for(int i=1;i<n;++i){ //we assume all elements to the left of i is sorted
        int j = i-1; //j is element of left of i
        int key = arr[i]; //storing value at index i to avoid losing it
        while(j>=0 && arr[j]>key){ //while arr to the left of i is greater than i
            arr[j+1] = arr[j]; //move the element to the right index
            j--; //check if the key element is lower than the other indexes to the left
        }
        arr[j+1] = key; //if no other index in the left is lower than the key, we set key in that index [We do j+1 since j got decremented in the last step]
    }
}

int main(){
    int arr[] = {5,2,4,8,11,96,-4,0,23,67,52,45};
    size_t n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted arr:\n";
    print_arr(arr,n);
    insertionSort(arr,n);
    cout<<"Sorted arr:\n";
    print_arr(arr,n);
}