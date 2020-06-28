//Checking if a pattern exists based on two pointer method.

#include<bits/stdc++.h>
using namespace std;

bool checkIfMatching(string &sentence, string &pattern){
	bool flag = false;
	for(int i=0,j=0;i<sentence.length();++i){
		if(sentence[i] == pattern[j] && j<pattern.length()){
			flag = true;
			++j;
			if(j==pattern.length()) return flag;
			continue;
		}else{
			flag = false;
			j=0;
		}
	}
	return flag;
}

int main(){
	string sentence = "abfsdabcsbabashdabnsabcfabcababcdekfabcskd";
	string pattern = "abcd";
	bool isMatching = checkIfMatching(sentence,pattern);
	cout<<isMatching<<endl;
}