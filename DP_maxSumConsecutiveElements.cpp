// DP
// Given an array of integers (positive and negative), find the largest sum of any non-consecutive integers

// Sample arr = {-5, 3, 4, -1, 2, 6}
// 1. Find dp array of 1 element, dp of 2 elements and so on.
// 2. Create a dp array of n elements where the value of n elements is stored in the index n of the array

// dp[1] = max(-5,0) = max(arr[0],0)
// dp[2] = max(-5,3) = max(arr[0],arr[1])
// dp[3] = max(-5+4, 3) = max(arr[0]+arr[2], arr[1])
// dp[4] = max(-1, 3)= max(arr[3] + dp[3], dp[n-1]) //Could be with the new element or without it
// dp[n] = arr[n-1] + dp[n-1]

#include<bits/stdc++.h>
using namespace std;

int getConsecutiveSum(int arr[], int n){
    int dp[n+1] = {0};
    dp[1] = max(0,arr[0]);
    int i = 2;
    while(i<=n){//To calculate all values of dp from 2 to n and store those values in array to use in the next iteration
        dp[i] = max(dp[i-1], arr[i-1] + dp[i-2]);
        ++i;
    }
    return dp[n];
}

int main(){
    int inputArr[] = {-5,3,4,-1,2,6};
    int n = sizeof(inputArr)/sizeof(inputArr[0]);
    int res = getConsecutiveSum(inputArr, n);
    cout<<res<<endl;
}
