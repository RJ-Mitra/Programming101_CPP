#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string word){
    int len = word.length();
    if(len<2) return true;
    int i=0,j=len-1;
    while(i<len/2 || j>len/2){
        if(word[i] == word[j]){
            ++i,--j;
        }
    }

    return false;
}

int main(){
    string word1 = "aba";
    string word2 = "hannah";
    string word3 = "chhhac";
}