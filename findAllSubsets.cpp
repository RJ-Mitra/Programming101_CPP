//Find all possible subsets from a given array

//Approach - Backtracking


#include<bits/stdc++.h>
using namespace std;

void getSubsetsUtil(vector<int>& arr, vector<vector<int>>& result, vector<int>& curr_subset, int index){
    result.push_back(curr_subset); //push the current subset into the result
    for(int i=index;i<arr.size();++i){ //i = index to continue from the prev call index
        curr_subset.push_back(arr[i]);
        getSubsetsUtil(arr,result,curr_subset,i+1); //if we use index+1 instead of i+1, it will take duplicated combinations as well (e.g 133 and 323)
        curr_subset.pop_back(); //backtracking
    }
}

vector<vector<int>> getSubsets(vector<int>& arr){
    vector<vector<int>> result;
    vector<int> curr_subset;
    int index = 0;
    getSubsetsUtil(arr,result,curr_subset,index);
    return result;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> res = getSubsets(arr);

    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size();++j){
            cout<<res[i][j];
        }
        cout<<"\n";
    }
}