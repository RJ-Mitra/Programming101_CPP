#include <bits/stdc++.h>
using namespace std;

//KMP pattern search
//O(n) runtime [O(n+m)]

void createLPS(string pat, vector<int> &lps){
    int len = 0;
    int forward = 1;
    while(forward<pat.size()){
        if(pat[len] == pat[forward]){
            ++len;
            lps[forward] = len;
            ++forward;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[forward] = len; //If len=0, that means no prefix exists for this. We set lps value for this char to 0.
                ++forward;
            }
        }
    }
}


void getMatchesKMP(string str, string pat){
    int str_ptr = 0;
    int pat_ptr = 0;
    bool isPresent = false;
    vector<int> lps(pat.size(),0);
    createLPS(pat,lps);
    while(str_ptr<str.size()){
        if(str[str_ptr] == pat[pat_ptr]){
            ++str_ptr;
            ++pat_ptr;
        }
        if(pat_ptr == pat.size()){
            isPresent = true;
            cout<<"Match found at index: "<<str_ptr-pat_ptr<<endl;
            ++str_ptr;
            pat_ptr=lps[pat_ptr-1];
        }else if(str[str_ptr] != pat[pat_ptr] && str_ptr<str.size()){
            if(pat_ptr!=0){
                pat_ptr=lps[pat_ptr-1]; //Fall back to the next known prefix, specified by LPS table
            }else{
                ++str_ptr; //if pat_ptr is back to 0, it means no prefix exists, we have to start matching from beginning of pattern from next string index
            }
        }
    }
    if(!isPresent) cout<<"No matches found."<<endl;
}


int main() {
	string str = "ADRSCRUDRUDRASRUSTDRUDAJISTRUARUDRLIRUDRAJIT";
	string pat = "RUDRA"; //LPS: 00010 (LPS index is assumed to start from 1, so last occurence of the second R is 1)
	getMatchesKMP(str,pat);
	return 0;
}
