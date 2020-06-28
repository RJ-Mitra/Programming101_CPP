//Counting sort

//Time complexity: O(n)
//Space complexity: linear

//Constraint notes: Should only be used when the max value of elements in the array is less than (array_size)^2.
//                  Won't be feasible if max value is 10000 and array size is 100 (So at most 100 unique elements spread over 10000 blocks)
#include<bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n){
	//Getting the max element in the array
    int max = 0;
	for(int i=0;i<n;++i){
		if(arr[i]>max) max=arr[i];
	}
    //Setting new array with length equal to max value
	int countArr[max+1];
	memset(countArr, 0, sizeof(countArr)); //Setting all array elements to 0
	//Storing count of all unique values in their respective indexes (if '0' comes twice, it is stored under index 0 with value 2)
    for(int i=0;i<n;++i){
		countArr[arr[i]]+=1;
	}
    //Normalising the array
	for(int i=1;i<=max;++i){
		countArr[i] = countArr[i-1] + countArr[i];
	}
    //Init new sorted Array with size same as input array
	int sortedArr[n];
    //Start from end of original array to maintain stability of sort
	for(int i=n-1; i>=0;--i){
		countArr[arr[i]] = countArr[arr[i]] - 1; //Check normalised value of each index and decrement it by 1 to get its sorted index
		sortedArr[countArr[arr[i]]] = arr[i]; //Store the value of input array in its sorted index in Sorted array
	}
    //Transfer sorted array to the original input array
	for(int i=0;i<n;++i){
		arr[i] = sortedArr[i];
	}
}

int main(){
	int arr[] = {23,1,7,19,13,5,8,19,1,25};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"Unsorted array: ";
	for(int i:arr) cout<<i<<" ";
	cout<<endl;
	cout<<"Sorted array: ";
	countingSort(arr,n);
	for(int i:arr) cout<<i<<" ";
}