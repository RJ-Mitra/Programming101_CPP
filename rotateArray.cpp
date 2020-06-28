/*
Left and Right rotate array k times
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int&b){
    int temp = a;
    a = b;
    b = temp;
}

void reverse(int* arr, int begin, int end){
    while(begin<end){
        swap(arr[begin++],arr[end--]);
    }
}

void rotateArrRight(int* arr, int n, int k){ //E.g. 1,2,3,4,5, k=2
    //step1: Reverse the entire array
    reverse(arr,0,n-1); //5,4,3,2,1
    //step2: Reverse the 1st k elements
    reverse(arr,0,k-1); //4,5,3,2,1
    //step3: Reverse the last k-1 elements
    reverse(arr,k,n-1); //4,5,1,2,3
}

void rotateArrLeft(int* arr, int n, int k){ //1,2,3,4,5, k=2
    //step1: Reverse the entire array
    reverse(arr,0,n-1); //5,4,3,2,1
    //step2: Reverse the last k elements
    reverse(arr,n-k,n-1); //5,4,3,1,2
    //step3: Reverse the first k-1 elements
    reverse(arr,0,n-k-1); //3,4,5,1,2
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10}; // 4,5,6,7,8,9,10,1,2,3
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    rotateArrLeft(arr,n,k);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    
}