#include<iostream>
using namespace std;

//Taylor series: e^n = x + x^2/2! + x^3/3! + x^4/4! +  ... + x^n/n!;

double taylorSeries(int x, int n){
    static double p = 1, f = 1; //static variables to keep track of power and factorial
    double r = 0;
    if(n==0) return 1;
    r = taylorSeries(x,n-1); //recursion call
    p = p*x;
    f = f*n;
    return r+p/f; //returns result in the format x + pow(x,n)/facorial(n);
}


int main(){
    int x = 3;
    int n = 10;
    cout<<taylorSeries(x,n)<<endl;;
}