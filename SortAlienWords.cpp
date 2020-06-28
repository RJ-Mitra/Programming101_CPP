#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

/*An alien language uses the same lower case alphabets as us, but in different lexicographical order.
Given a number of words and the lexicographical order, find whether the words are in sorted order. */

bool checkSortingOrder(vector<string> words, string order){
    //
    int orderLen = order.length();

    //Returns vector of aphabets with their orders in alien language
    //Example: 5,6,7,4,8, signifying a is the 5th element, b is 6th and so on in alien language
    vector<int> alphaOrder(orderLen,0);
    for(int i=0;i<orderLen;++i){
        alphaOrder[order[i]-'a'] = i;
    }
    
    //Iterates through word list and compares words
    for(int i=0;i<words.size();++i){
        for(int j=i+1; j<words.size();++j){
            int min_size = min(words[i].size(),words[j].size());
            for(int k=0;k<min_size;++k){
                char i_char = words[i][k];
                char j_char = words[j][k];
                if(alphaOrder[i_char-'a'] < alphaOrder[j_char-'a']) break;
                else if(alphaOrder[i_char-'a'] > alphaOrder[j_char-'a']) return false;
                else if(k+1==min_size && words[i].size()>words[j].size()) return false;
            }
        }
    }
    return true;
}


int main(){
    string order = "worldabcefghijkmnpqstuvxyz";
    //vector<string> words = {"word","world","hello","alien","order","or"};
    vector<string> words = {"or","order"};
    bool isSorted = checkSortingOrder(words,order);
    cout<<isSorted<<endl;
}
