//Find first duplicate

#include<bits/stdc++.h>
using namespace std;


//1. Constraints: Integer array. x>0 and x< size of array.
//Time AND Space constraints

int getFirstDuplicate(int arr[], int size){
	for(int i=0;i<size;i++){
		if(arr[arr[i]]<0){
			return i;
		}else{
			arr[arr[i]] = arr[arr[i]]*-1;
		}
	}
	return -1;
}

int main(){
	int inputArr[] = {2,5,1,7,2,3,5};
	int size = sizeof(inputArr)/sizeof(inputArr[0]);
	//cout<<size<<endl;
	int index = getFirstDuplicate(inputArr,size);
	cout<<index<<endl;
}



//No space constraints (using set)

// int main(){
// 	string inputStr = "samhita";
// 	unordered_set<char> charSet;
// 	for(char i:inputStr){
// 		if(charSet.find(i) == charSet.end()){
// 			charSet.insert(i);
// 		}else{
// 			cout<<i<<endl;
// 		}
// 	}
// }