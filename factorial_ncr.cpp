//Factorials
//nCr = n!/r!*(n-r!)

#include<iostream>
using namespace std;

//factorial
int factorial(int n){
    if(n==0) return 1;
    return factorial(n-1)*n;
}

//Iterative

int ncr(int n, int r){
    int numerator = factorial(n);
    int denominator = factorial(r) * factorial(n-r);
    return numerator/denominator;
}


//Recursive (also used in Pascal's triangle)

int NCR(int n, int r){
    if(n==r || r==0) return 1;
    return NCR(n-1,r-1)+NCR(n-1,r);
}

//Pascal's triangle
/*
        1
    1   2   1
1   2   3   2   1
*/


//O(n^3)
void print_pascal(int n){
    for(int line=0;line<n;line++){
        for(int i=0;i<=line;++i){
            cout<<NCR(line,i)<<" ";
        }
        cout<<"\n";
    }
}


int main(){
    print_pascal(5);
}
