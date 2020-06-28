//Radix sort OR Bucket Sort

#include<bits/stdc++.h>
using namespace std;

//Getting the max element to determine number of loops required (based on number of digits of max element)
int getMax(int arr[], int n){
	int max = 0;
	for(int i=0;i<n;++i){
		if(arr[i] > max) max = arr[i];
	}
	return max;
}

//Modified counting sort to take sort the array based on position (units,tens,hundreds and so on)
void countingSort(int arr[], int n, int pos){
	int countArray[10] = {0};
	for(int i=0;i<n;++i){
		++countArray[(arr[i]/pos)%10]; //To sort based on the digit pos for that loop (e.g. ten's place)
	}
	for(int i=1;i<10;++i){
		countArray[i] = countArray[i] + countArray[i-1];
	}
	int sortedArr[n];
	for(int i=n-1;i>=0;--i){
		sortedArr[--countArray[(arr[i]/pos)%10]] = arr[i]; //Same as counting sort
	}
	for(int i=0;i<n;++i){ //Getting sorted values back into the original array
		arr[i] = sortedArr[i];
	}
}

//Main radix sort call
void radixSort(int arr[], int n){
	int max = getMax(arr,n); //Gets max element
	for(int pos=1;max/pos>0;pos*=10){ //Starts with unit's place (least significant digit) and loops till the most significant digit
		countingSort(arr, n, pos);
	}
}


int main(){
	int arr[] = {23,15,98,21,203,672};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i:arr) cout<<i<<" ";
	cout<<endl;

	radixSort(arr,n);

	for(int i:arr) cout<<i<<" ";
	cout<<endl;
}
