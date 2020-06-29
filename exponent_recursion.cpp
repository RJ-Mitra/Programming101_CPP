#include<iostream>
using namespace std;

//power of m^n
int pow(int m, int n){
    if(n==0) return 1;
    else return pow(m,n-1)*m;
}

//since 2^8 can be written as (2^2)^4 , we can reduce the number of  calls by half
int pow2(int m, int n){
    if(n==0) return 1;
    if(n&1){//if n is odd
        return m*pow(m*m,(n-1)/2);
    }else{
        return pow(m*m,n/2);
    }
}

int main(){
    int m = 4;
    int n = 2;
    cout<<pow2(m,n)<<endl;
}