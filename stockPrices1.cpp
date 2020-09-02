//Buy and Sell stocks to make maximum profit

//Given a list of stock prices, find the maximum profit that can be attained
//by buying and selling the stocks.
//Stocks can only be sold after buying.
//More than 1 transaction cannot take place simultaneously


//Approach - Since transactions are unlimited, we sell whenever there is a increase in the slope
//           and we do not sell when there is a decrease

#include<bits/stdc++.h>
using namespace std;

int getMaxProfit(vector<int>& stock_prices){
    int max_profit = 0;
    for(int i=1;i<stock_prices.size();++i){
        if(stock_prices[i]>stock_prices[i-1]){
            max_profit+=stock_prices[i]-stock_prices[i-1];
        }
    }
    return max_profit;
}

int main(){
    vector<int> stock_prices = {7,5,1,4,3,6,8,2};
    cout<<getMaxProfit(stock_prices);
}