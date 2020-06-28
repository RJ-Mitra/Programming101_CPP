#include <bits/stdc++.h> 
using namespace std;

//Function to sort and merge the two sub-arrays
void merge(int arr[], int l, int r){
    int mid = l+(r-l)/2;
    int i,j,k;
    //Getting size of sub-arrays
    int nl = mid-l+1;
    int nr = r-mid;

    //Creating temp arrays with sizes abova
    int L[nl],R[nr];
    //populating values into sub-arrays
    for(i=0;i<nl;++i){
        L[i] = arr[l+i];
    }
    for(j=0;j<nr;++j){
        R[j] = arr[mid+1+j];
    }

    //Merging temp arrays into main array
    i = j = 0;//Index of two sub-arrays
    k=l;//Index of merged array
    while(i<nl && j<nr){
        if(L[i] >= R[j]){
            arr[k] = R[j];
            k++;
            j++;
        }else{
            arr[k] = L[i];
            k++;
            i++;
        }
    }

    //If any elements are remaining after this, insert them in the array
    while(i<nl){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r){
    //If array has more than 1 element
    if(r>l){
        //getting mid point for dividing array
        int mid = l+(r-l)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr,l,r);
    }
}

int main(){
    int n = 8;
    int arr[n] = {12,10,9,16,2,23,0,21};
    mergeSort(arr,0,n-1);

    for(int i:arr){
        cout<<i<<std::endl;
    }
}