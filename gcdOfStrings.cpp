/*
Find GCD of two strings
GCD of strings "ABCABCAB" and "ABC" is "", since no common divisor is present
GCD of "ABABAB" and "AB" is AB, since AB can divide ABABAB wholly.
*/

#include<bits/stdc++.h>
using namespace std;

//Function to find GCD of two numbers
int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

string gcdOfStrings(string &str1, string &str2) {
    if(str1+str2 != str2+str1) return ""; //if one string is not prefix of another, then no GCD is possible. E.g ABAB and AB (true) but ABCAB and AB (false)
    if(str1==str2) return str1; //if both strings are identical, anyone of them can divide the other wholly
    return str1.substr(0,gcd(str1.size(),str2.size())); //get gcd of the length of 2 strings and return a substring of the larger string with that length
}

int main(){
    string a = "ABABAB";
    string b = "AB";
    cout<<gcdOfStrings(a,b);
}