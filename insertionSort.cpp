#include <bits/stdc++.h> 
using namespace std;



void insertionSort(int arr[], int n){
    //outer for loop to iterate over each array element
    int i,j,key;
    for(i=1;i<n;++i){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}


int main(){
    int n = 5;
    int arr[n] = {12,10,9,16,2};
    insertionSort(arr,n);

    for(int i:arr){
        cout<<i<<std::endl;
    }
}