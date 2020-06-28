#include<bits/stdc++.h>
using namespace std;

int getPositiveSum(int* arr, int n, int i){
    if(i>=n) return 0;
    int sum_curr = 0;
    if(arr[i] >= 0) sum_curr = arr[i];
    int sum_pos = getPositiveSum(arr,n,i+1);
    return sum_pos + sum_curr;
}

int main(){
    int arr[] = {3,-1,7,4,-9,6,2,-4,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = getPositiveSum(arr,n,0);
    cout<<sum<<endl;
}