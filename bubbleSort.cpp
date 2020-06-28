#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int i = 0;
    int j = n-1;
    bool sorted = false;
    while(!sorted){
        sorted=true;
        for(i=0;i<j;i++){
            if(arr[i]>arr[i+1]){
                sorted=false;
                swap(&arr[i],&arr[i+1]);
            }
        }

    }
}


int main(){
    int n = 8;
    int arr[n] = {89,23,45,0,34,7,32,10};
    bubbleSort(arr,n);
    for(int i:arr){
        cout<<i<<" ";
    }
}