//Find sum of elements of two arrays. Return true if their sum is equal to the given sum.

#include<bits/stdc++.h>
using namespace std;

bool checkSumOfTwo(int arr1[], int arr2[], int n1, int n2, int sum){
	unordered_set<int> calcSet;
	for(int i=0;i<n1;++i){
		calcSet.insert(calcSet.end(),sum-arr1[i]);
	}
	for(int i=0;i<n2;++i){
		if(!(calcSet.find(arr2[i]) == calcSet.end())) return true;
	}
	return false;
}

int main(){
	int arr1[] = {2,4,6,8,-10,-23};
	int arr2[] = {32,8,23,10};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);

	int sum = 25;

	bool res = checkSumOfTwo(arr1,arr2,n1,n2,sum);
	cout<<res<<endl;
}