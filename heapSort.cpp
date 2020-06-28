#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

void heapify(int arr[], int n, int i){
	int largest = i;
	int leftChild = 2*i+1;
	int rightChild = 2*i+2;
	if(arr[leftChild]>arr[i] && leftChild<n) largest = leftChild;
	if(arr[rightChild] > arr[largest] && rightChild<n) largest = rightChild;
	if(largest!=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);//heapify the affected branch
	}
}


void heapSort(int arr[], int n){
	for(int i=n/2-1;i>=0;i--){//heapify the array
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);//send 1st element(largest in max heap) to the end of the array. Bring last element to 0th index.
		heapify(arr,i,0);//heapify reduced heap. i->reduced size of array. n=0 -> starts heapify from the 1st element till i (since each sorted element gets added back to the end)
	}
}

int main(){
	int inputarr[] = {2,18,30,27,15,12};
	int n = sizeof(inputarr)/sizeof(inputarr[0]);
	heapSort(inputarr, n);
	
	for(int j:inputarr){
		cout<<j<<endl;
	}
}