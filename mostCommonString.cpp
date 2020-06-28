#include<bits/stdc++.h>
using namespace std;


char getMostCommonLetter(string inputStr, int *count){
	map<char,int> charMap;
	char key;
	for(char i:inputStr){
		if ( charMap.find(i) == charMap.end()){
			charMap.insert({i,1});
		}else{
			charMap[i]+=1;
		}
	}
	for(auto it = charMap.cbegin(); it != charMap.cend(); ++it){
		if(it->second >*count){
			key = it->first;
			*count=it->second;
		}
	}
	return key;
}


int main(){
	string testStr = "rudrajit";
	int count = 0;
	char result = getMostCommonLetter(testStr,&count);
	cout<<"Character "<<result<<" occurs "<<count<<" times in the string "<<testStr<<endl;
}