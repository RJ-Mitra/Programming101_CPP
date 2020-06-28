#include <bits/stdc++.h> 
using namespace std;


int jumpSearch(int arr[], int n, int x){
    int jump = sqrt(n);
    int prev;
    while(arr[min(jump,n)-1] < x){
        prev = jump;
        jump+=sqrt(n);
        if(prev>=n){
            return -1;
        }
    }
    while(arr[prev]<x){
        prev++;
        if(prev==min(jump,n)){
            return -1;
        }
    }
    if(arr[prev] == x){
        return prev;
    }
    return -1;
}


int main(){
    int n = 8;
    int x = 72;
    int arr[n] = {1,4,7,19,23,56,72,93};
    
    int indexOfElement = jumpSearch(arr,n,x);

    if(indexOfElement == -1){
        cout<<"Element not in array."<<std::endl;
    }else{
        cout<<"Index of element "<< x <<" is at "<<indexOfElement<<std::endl;
    }
}
