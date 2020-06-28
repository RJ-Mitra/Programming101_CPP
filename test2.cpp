#include<bits/stdc++.h>
using namespace std;


int main(){
    int *pi = new int(5);
    int *pi2 = pi;
    pi = new int(16);
    assert(pi2 != pi);

    int *pj = pi;
    *pj+=5;
    cout<<*pi<<endl;
}