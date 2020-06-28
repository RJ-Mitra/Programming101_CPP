//Rotating matrix 90 degs - using vector

#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}


void rotateMatrix(vector<vector<int>> &vec){
    int row = vec.size();
    int col = vec[0].size();

    //Step 1: Transpose
    for(int i=0;i<row;++i){
        for(int j=i;j<col;++j){
            swap(&vec[i][j], &vec[j][i]);
        }
    }
    //Step 2: Swap first and last elements as we go inward
    for(int i=0;i<row;++i){
        for(int j=0;j<col/2;++j){
            swap(&vec[i][j],&vec[i][col-1-j]);
        }
    }
}



int main(){

	vector<vector<int>> vec =  {{1,  2, 3, 4},
				     		    {5,  6, 7, 8},
				     		    {9, 10,11,12},
				     		    {13,14,15,16}};
    int size = vec.size();
	
	//Display array
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}

    cout<<endl;
    rotateMatrix(vec);
    cout<<"Rotated 90 degrees"<<endl;
    cout<<endl;

    //Display array
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}

}
