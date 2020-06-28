#include<bits/stdc++.h>
using namespace std;

bool palindrome(std::string input){
    vector<char> inputStr;
    for(char i : input){
        inputStr.push_back(i);
    }
    int length = inputStr.size();
    int i = 0;
    int j = length-1;
    while(i<=(length/2)){
        if(inputStr[i] == inputStr[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}



int main(){
    bool isPalindrome = palindrome("sasafdasas");
    cout<<isPalindrome<<std::endl;
}