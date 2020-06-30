//DP Problem: Ways of climbing stairs
//You are climbing a staircase that takes n steps to reach the top. You can either climb 1 or 2 steps each time.
//In how many distinct ways can you climb to the top?
//(n will always be positive)


//ways of climbing stairs -> one at a time, 2 at a time

//dp[1] = 1,
//dp[2] = 2, (2 ways of climbing 2 stairs. 1 at a time x 2, or two at a time x 1)
//dp[3] = 3,  (2,1; 1,1,1; 1,2)
//dp[4] = 5, (2,2; 1,1,1,1; 1,2,1; 2,1,1; 1,1,2)
//dp[5] = 8 , (2,2,1; 1,2,2; 2,1,2; 1,1,1,1,1; 1,1,1,2; 2,1,1,1; 1,1,2,1; 1,2,1,1)
//Results follow fibonacci pattern

//dp[n] = dp[n-1] + dp[n-2];

#include<cmath>
#include<bits/stdc++.h>

using std::cin;
using std::cout;


int climbingStairs(int n){
    int dp[n+1] = {0};//Initializing dp array
    dp[0] = 1;//Only one way to climb 0 steps - Not climbing it
    dp[1] = 1;//Can be climbed only once
    for(int i=2;i<=n;++i){
        dp[i] = dp[i-1]+dp[i-2];//Can come to it after climbing 1 step or 2 steps
    }
    return dp[n];
}
//All dp[n] are being calculated in the loop, so when we get to dp[10], we already have dp[9],dp[8], etc calculated before in the loop

int main(){
    int stairs_res = climbingStairs(3);
    cout<<stairs_res;
}
