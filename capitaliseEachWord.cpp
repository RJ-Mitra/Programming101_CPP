#include<bits/stdc++.h>
using namespace std;

void capitaliseString(string &inputStr){
	inputStr[0] = inputStr[0]-32;
	for(int i=1;i<inputStr.length();++i){
		if(inputStr[i-1] == ' ' || inputStr[i-1] == NULL){
			inputStr[i] = inputStr[i]-32;
		}
	}
}

int main(){
	string str1 = "hi this is rudra.";
	capitaliseString(str1);
	cout<<str1;
}