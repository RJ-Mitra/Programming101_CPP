//Rabin Karp pattern matching with rolling hash function

#include<bits/stdc++.h>
using namespace std;

#define d 256
//d is the maximum number of characters possible

void getMatchesRabinKarp(string txt, string pat){
    bool isMatching = false;
    int txt_size = txt.size();
    int pat_size = pat.size();
    int txt_hash = 0;
    int pat_hash = 0;
    int i,j;
    int q = 101; //A prime number for hashing
    int h = 1; //h is the highest significant digit of the pattern. E.g if pattern is 234, h is 100.
               //In case of decimal system, h would have increased by 10. E.g. 132 = 1*100 + 3*10 + 2*1
               //Here, h increases by 256 (d)
    //Calculating value of h
    for(i=0;i<pat_size-1;++i){ //pat_size minus one since we don't need to increase for unit's place. (h=1)
        h=(h*d)%q;//mod by q to keep the values lower so that they fit into int data type.
    }
    //Calculating hash values of pattern and 1st string window
    for(i=0;i<pat_size;++i){
        pat_hash = (d * pat_hash + pat[i])%q; //E.g 234 = 0+2 -> 2*10+3 -> 23*10+4 -> 234 
        txt_hash = (d * txt_hash + txt[i])%q; //We mod it by a prime to keep the hash values low
    }
    //Matching patterns
    for(i=0;i<=txt_size-pat_size;++i){
        if(pat_hash == txt_hash){//if hash of pattern matches hash of the txt window
            for(j=0;j<pat_size;++j){//We go in and make sure all txt values are matching pat values to weed out false negatives
                if(pat[j]!=txt[i+j]) break;
            }
            if(j==pat_size){//If all elements are matching, we found a match
                isMatching = true;
                cout<<"Pattern found at index: "<<i<<endl;
            }
        }
        if(i<txt_size-pat_size){//If not matching, we rehash the txt window by
            txt_hash = (((txt_hash - txt[i]*h)*d)+ txt[i+pat_size])%q; // removing the 1st digit of txt window((elem at index i) * h) and add the last element (at index i+m) [m-> len of window]. Multiplying by d (say 10 in case f decimal) to change it to next significant place
            if(txt_hash<0) txt_hash+=q; //If the txt hash value comes to be negative, we turn it to positive
        } //E.g. 2345-> 234 and 345 -> 10*(234-2*100)->340+5->345. Again mod by prime to keep hash values low.
    }
    if(!isMatching) cout<<"No matches found in the text."<<endl;
}

int main(){
    string txt = "HELLORUDRAWHATARUDOINGRUDRUDRAJITRUDRO";
    string pat = "RUDRA";
    getMatchesRabinKarp(txt,pat);
    return 0;
    
}