#include<bits/stdc++.h>
using namespace std;

//aabcdaabc
void createLPS(vector<int> &lps, string pattern){
	int len = 0; //size of largest prefix suffix till now
	lps.push_back(0); //1st element will always be 0 since one element can't have prefix suffix
	int i = 1; //starting from the 2nd index
	while(i<pattern.length()){
		if(pattern[i] == pattern[len]){//if matching
			++len;
			lps.push_back(len); //assigns lps value to that element
			++i;
		}
		if(pattern[i] != pattern[len] && i<pattern.length()){//if not matching
			if(len!=0){
				len=lps[len-1]; //check lps table for which element to fall back to. Not incrementing i.
			}else{
				lps.push_back(len); //if lenght is 0 and still not getting a match, we assign 0 (len) and increment i, move on to next
				++i;
			}
		}
	}
}

vector<int> getMatchKMP(string sentence, string pattern){
	int i = 0;//setting main iterator to 0 (for sentence)
	int j = 0;//setting pattern iterator to 0
	vector<int> lps;
	vector<int> matchIndex;
	createLPS(lps, pattern); //getting lps table for pattern
	while(i<sentence.length()){ //main loop
		if(sentence[i] == pattern[j]){ //if matching, increment both pointers to check next element
			++i;
			++j;
		}
		if(pattern.length() == j){ //if j is matching length of pattern, all elements are matching completely
			matchIndex.push_back(i-j);
			j = lps[j-1]; // Checks lps table to fall back to last seen prefix (j not resetting to 0)
		}else if(sentence[i] != pattern[j] && i<sentence.length()){ //if not matching
			if(j!=0){
				j=lps[j-1]; //Checks lps to see which element to fall back to
			}else{
				++i; //Still no matches found and j=0, so increments i and moves on
			}
		}
	}
	if(matchIndex.size()<1) return {-1};
	else return matchIndex; //returns matched index(es) as vector
}

//Driver function
int main(){
	string sentence = "abfsdabcsbabcabdashdabnsabcfabcababcabcabdabcabd";
	string pattern = "abcabd";
	vector<int> res  = getMatchKMP(sentence,pattern);
	if(res[0] == -1) cout<<"No matches found."<<endl;
	else{
		for(int i:res) cout<<"Match found at index "<<i<<endl;
	}
}