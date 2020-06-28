#include <bits/stdc++.h>
using namespace std;

//O(logn) time, O(1) space

#define ll long long

ll getLastDigit(ll a, ll b){
    ll result = 1;
    if(b==1) return a%10; //Since any base to the power 1 is the base itself
    while(b>0){ //till the power is greater than 0
        if(b&1){//bit checking if the last digit is 1 0r 0. If last digit is 1, 1&1 return 1, which is true
            result=result*a;//if last digit is 0, multiplying result to it will only return 0.
        }
        a=a*a; //We increment a
        b=b>>1;//We bit shift b to the right to remove the last digit and take the 2nd last digit into account
    }
    return result%10;//We mod final result by 10 to get the last digit of the result
}

int main() {
	ll res = getLastDigit(5,3);
	cout<<res<<endl;
	return 0;
}
