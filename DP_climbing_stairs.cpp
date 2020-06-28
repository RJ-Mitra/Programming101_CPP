//DP Problem: Ways of climbing stairs
//You are climbing a staircase that takes n steps to reach the top. You can either climb 1 or 2 steps each time.
//In how many distinct ways can you climb to the top?
//(n will always be positive)

#include<cmath>
#include<bits/stdc++.h>
#include<iostream>

using std::cin;
using std::cout;


int climbingStairs(int n){
    int dp[n+1];//To handle base case 0, since only 1 way of climbing 0 stairs
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
