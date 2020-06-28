#include <bits/stdc++.h> 
using namespace std; 
int interpolationSearch(int arr[], int n, int x){
    int low = 0;
    int high = n-1;
    int pos;
    while(low<=high && arr[high]>= x && arr[low]<=x){
        if(low==high){
            if(arr[low] == x){
                return low;
            }
            return -1;
        }
        pos = low + ((((double)(high-low))/(arr[high]-arr[low]))*(x-arr[low]));
        if(arr[pos] == x){
            return pos;
        }
        if(arr[pos] > x){
            high = pos - 1;
        }else{
            low = pos + 1;
        }
    }
    return -1;
}


int main(){
    int n = 8;
    int x = 47;
    int arr[n] = {7,11,26,34,47,51,62,78};
    int indexOfElem = interpolationSearch(arr,n,x);
    if(indexOfElem == -1){
        cout<<"Element is not in array."<<std::endl;
    }else{
        cout<<"Element "<<x<<" is at index "<<indexOfElem<<std::endl;
    }
}