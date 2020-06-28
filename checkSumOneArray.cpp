//Google
//Check if an array has elements equal to a provided sum value.

#include<bits/stdc++.h>
using namespace std;

bool checkSumOfArray(vector<int> inputVec, int sum){
	unordered_set<int> complement;
	for(int i=0;i<inputVec.size();++i){
		if(complement.find(inputVec[i]) != complement.end()){
			return true;
		}else{
			complement.insert(sum-inputVec[i]);
		}
	}
	return false;
}

int main(){
	vector<int> input = {2,6,-4,7,12,6,3};
	int sum = 11;
	bool isPresent = checkSumOfArray(input,sum);
	cout<<isPresent<<endl;
}