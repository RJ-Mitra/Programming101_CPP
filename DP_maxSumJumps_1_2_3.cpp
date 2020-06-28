#include<bits/stdc++.h>
using namespace std;

//Traverse array using jumps of 1,2 or 3 steps at a time
//Find max sum of the jumps

//arr[] = {2,-3,-5,9,13,24}
//dp[1] = 1 -> 1
//dp[2] = 1,1 ; 2 -> 2
//dp[3] = 1,1,1; 2,1; 1,2 -> 3

//dp[4] = 9+max(dp[3],dp[2],dp[1])

int getMaxValue(int a, int b, int c){
    return max(a,max(b,c));
}

int getMaxValue(int a, int b){
    return max(a,b);
}

int getMaxJumpValue(int arr[], int n){
    int dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = arr[0];
    dp[2] = arr[1] + arr[0];
    dp[3] = arr[2] + getMaxValue(dp[1], dp[2]);
    dp[4] = arr[3] + getMaxValue(dp[3], dp[2], dp[1]);
    //dp[i] = getMaxValue(arr[i-1]+dp[i-1], arr[i-1]+dp[i-2], arr[i-1]+dp[i-3])
    int i = 5;
    while(i<=n){
        dp[i] = arr[i-1] + getMaxValue(dp[i-1], dp[i-2], dp[i-3]);
        ++i;
    }
    return dp[n];
}

int main(){
    // int arr[] = {21,-4,7,3,21,-40,-28,-12,-3,67,12,98};
    int arr[] = {4,-2,3,5,-4,100};
    int n = sizeof(arr)/sizeof(arr[0]); //n stairs
    int res = getMaxJumpValue(arr,n);//ways of climbing n stairs
    cout<<res<<endl;
}