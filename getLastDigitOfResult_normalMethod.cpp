#include <bits/stdc++.h>
using namespace std;

//O(logn) time, O(logn) space

#define ll long long

ll getLastDigit(ll a, ll b){
    ll result = 1;
    if(b==1) return a%10; //Since any base to the power 1 is the base itself
    while(b>=1){
        if((b&1)){ //bit masking to find is b is odd. If b is odd, last digit will be 1. 1&1 will return 1, which evals to true
            result=result*a;
        }
        a=a*a;
        b=b/2;
    }
    return result%10;
}

int main() {
	ll res = getLastDigit(5,3);
	cout<<res<<endl;
	return 0;
}
