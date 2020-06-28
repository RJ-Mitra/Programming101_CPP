#include<bits/stdc++.h>
using namespace std;

bool hasOddBits(string bits){
    if(bits.size()==0) return 0;
    return ((bits[0]-'0'?1:0)^(hasOddBits(bits.substr(1)))); //entire string without the 0th element
}

bool hasOddBits_Iter(string bits){
    int count = 0;
    for(int i=0;i<bits.size();++i){
        if(bits[i]-'0') ++count;
    }
    return count&1;
}

int main(){
    string bits = "1100010101";
    bool isOdd = hasOddBits(bits);
    cout<<isOdd<<endl;
}