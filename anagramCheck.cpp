//Anagram check
//Needs optimisation

#include<bits/stdc++.h>
using namespace std;


template<typename Map>
bool key_compare (Map const &lhs, Map const &rhs) {
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(), rhs.begin(), 
                      [] (auto a, auto b) { return a.first == b.first; });
}


bool checkAnagram(string inputStr1, string inputStr2){
	inputStr1.erase(remove_if(inputStr1.begin(), inputStr1.end(),
	[](char c){
		return isspace(c) || !isalpha(c);
	}), inputStr1.end());
	transform(inputStr1.begin(), inputStr1.end(), inputStr1.begin(), ::tolower);

	inputStr2.erase(remove_if(inputStr2.begin(), inputStr2.end(),
	[](char c){
		return isspace(c) || !isalpha(c);
	}), inputStr2.end());
	transform(inputStr2.begin(), inputStr2.end(), inputStr2.begin(), ::tolower);

	cout<<inputStr1<<endl;
	cout<<inputStr2<<endl;

	if(inputStr1.length() != inputStr2.length()) return false;

	map<char,int> charMapA;
	map<char,int>::iterator itA;
	for(char c:inputStr1){
		itA = charMapA.find(c);
		if(itA!=charMapA.end()){
			charMapA[c]+=1;
		}else{
			charMapA.insert({c,1});
		}
	}

	map<char,int> charMapB;
	map<char,int>::iterator itB;
	for(char c:inputStr1){
		itB = charMapB.find(c);
		if(itB!=charMapB.end()){
			charMapB[c]+=1;
		}else{
			charMapB.insert({c,1});
		}
	}

	return key_compare(charMapA, charMapB);
}

int main(){
	string a = "hello! I am here.";
	string b = "olleh, aI m erhew;";
	bool res = checkAnagram(a,b);
	cout<<res<<endl;
}