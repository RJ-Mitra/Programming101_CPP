//Rotate a square array matrix 90 degrees

#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}


int main(){

	int size = 4;
	int arr[size][size] =  {{1,  2, 3, 4},
				     		{5,  6, 7, 8},
				     		{9, 10,11,12},
				     		{13,14,15,16}};
	
	//Display array
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}


	//Rotation starts

	//Step1: Transpose the array (Transform rows into columns)(swap diagonally opp elements)
	for(int i=0;i<size;i++){
		for(int j=i;j<size;j++){
			swap(&arr[i][j], &arr[j][i]);
		}
	}

	cout<<endl;
	//Display array
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	//Rows got tranformed into columns

	//Step2: Swap 1st and last elements of each row in the array, going inwards from both end
	for(int i=0;i<size;i++){
		for(int j=0;j<size/2;j++){
			swap(&arr[i][j],&arr[i][size-1-j]);
		}
	}

	cout<<endl;
	//Display array
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

}
