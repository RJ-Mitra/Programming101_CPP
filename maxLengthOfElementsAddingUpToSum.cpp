//Facebook
//Find the maximum length of successive elements that add up to a given sum

#include<bits/stdc++.h>
using namespace std;

vector<int> getLongestIndex(vector<int> inputVec, int sum){
	vector<int> res;
	int min_index = 0;
	int max_index = 0;
	int max_length = 0;
	int sum_val = 0;
	bool found = false;
	for(int right=0, left = 0;right<inputVec.size();++right){
		sum_val+=inputVec[right];
		while(sum_val > sum && left<inputVec.size()){
			sum_val-=inputVec[left];
			left++;
		}
		if(sum_val == sum && (right-left)>max_length){
			found = true;
			max_length = right-left+1;
			min_index = left;
			max_index = right;
		}
	}
	if(!found) res.push_back(-1);
	else{
		res.push_back(min_index);
		res.push_back(max_index);
		res.push_back(max_length);
	}
	return res;
}
int main(){
	vector<int> inputVec = {1,2,3,4,5,0,0,0,5,7,3,9,8,7,1,1,1,0,0,0,0,3,2,0};
	int sum = 15;
	vector<int> res = getLongestIndex(inputVec,sum);
	if(res[0]==-1){
		cout<<"No sum found in provided list."<<endl;
	}else{
		cout<<"Largest length of successive values that add up to "<<sum<<" starts from index "<<res[0]<<" till index "<<res[1]<<" and has a length of "<<res[2]<<" units."<<endl;
	}

}
