//Taylor's series using Horner's rule
//Taylor series: e^n = 1 + x + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n!
//Horner's rule: Keep taking common factors to reduce the number of multiplications from O(n^2) to O(n)
/*
e^4 = 1 + x + x^2/2*1 + x^3/3*2*1 + x^4/4*3*2*1!
e^4 = 1 + x/1[1 + x/2 + x^2/3*2 + x^3/4*3*2]
e^4 = 1 + x/1[1 + x/2[ 1 + x/3 + x^2/4*3]]
e^4 = 1 + x/1[1 + x/2[ 1 + x/3 [ 1 + x/4]]]

4 steps for n = 4. Therefore, O(n)
*/

#include<iostream>
using namespace std;

//recursive

double e_recur(int x, int n){
    double static sum = 1; //Sum is static, keeps accumulating the s value E.g. 1+x/n * 1+x/n-1 and so on
    if(n==0) return sum;
    sum = 1+x * sum / n; //Formula: 1 + x/n * sum
    return e_recur(x,n-1);
}


//iterative

double e_iter(int x, int n){
    double sum = 1;
    double numerator = 1;
    double denominator = 1;
    for(int i=1;i<=n;++i){
        numerator = numerator*x; //To get power
        denominator = denominator*i; //To get factorial
        sum+=numerator/denominator; //Gets sum;
    }
    return sum;
}


int main(){
    int x = 1;
    int n = 10;
    cout<<"Recur: "<<e_recur(x,n)<<endl;
    cout<<"Iter: "<<e_iter(x,n)<<endl;
}
