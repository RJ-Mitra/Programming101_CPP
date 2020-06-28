#include <bits/stdc++.h> 
using namespace std;


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_fun(int arr[], int left_pointer, int right_pointer){
    int pivot_index = right_pointer;
    int pivot_value = arr[pivot_index];
    right_pointer -= 1;
    
    while(true){
        while(arr[left_pointer]<pivot_value){
            left_pointer++;
        }
        while(arr[right_pointer]>pivot_value){
            right_pointer--;
        }
        if(left_pointer >= right_pointer){
            break;
        }else{
            swap(&arr[left_pointer],&arr[right_pointer]);
        }
    }
    swap(&arr[left_pointer],&arr[pivot_index]);
    return left_pointer;
}

void quickSort(int arr[], int low, int hi){
    if(hi>low){
        int partition_pos = partition_fun(arr,low,hi);

        quickSort(arr,low,partition_pos-1);
        quickSort(arr,partition_pos+1, hi);
    }
}


int main(){
    int n = 8;
    int arr[n] = {12,10,9,16,2,23,0,21};
    
    quickSort(arr,0,n-1);

    for(int i:arr){
        cout<<i<<std::endl;
    }
}
