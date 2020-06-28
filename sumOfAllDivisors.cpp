//Find sum of all divisors of a given number

#include<bits/stdc++.h>
using namespace std;


int main(){
    int num = 100;
    int sum = 0;
    
    for(int i=2;i<=sqrt(num);i++){ //take till sqrt of a number
        if(num%i==0){//check if num is divisible by the number in loop
            if(i==num/i) sum+=i; //if divisor is same as quotient, add only divisor
            else sum+=(num/i)+i; //Add both divisor and the quotient (since num is also divisible by quotient, but quo will be greater than sqrt of num)
        }
    }
    cout<<sum+1<<endl; //returning sum+1 since all nums are also divisible by 1
}