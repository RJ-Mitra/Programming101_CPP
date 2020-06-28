#include<bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int left, int right, int x){
    if(left<=right && x>=arr[left] && x<=arr[right]){
        if(left==right){
            if(arr[left]==x) return left;
        }
        
        int pos = left + (((double)(right - left)/(arr[right] - arr[left])) * (x - arr[left]));
        if(arr[pos] == x) return pos;
        if(arr[pos]>x){//
            interpolationSearch(arr,left,pos-1,x);
        }else{
            interpolationSearch(arr,pos+1,right,x);
        }
    }
    return -1;
}

int main(){
    int x = 78;
    int n = 8;
    int arr[n] = {12,23,34,45,56,67,78,89};
    int index = interpolationSearch(arr,0,n-1,x);
    cout<<index<<std::endl;
}