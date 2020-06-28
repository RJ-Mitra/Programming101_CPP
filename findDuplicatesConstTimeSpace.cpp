// Find the elements which are ocurring twice in an array of positive integers. The max element will not be greater than the size of the array.
//0<x<=N
//Constant time and space solution
//Set the element at the index of the current element to negative.
//If we encounter a negative element, we know it was encountered before
//We print the recurring element.
//Element needs to be set to positive(abs) before asignment, print

#include <bits/stdc++.h>
using namespace std;

void getMultipleOccurances(vector<int> &vec){
    vector<int> res;
    for(int i=0;i<vec.size();++i){
        if(vec[abs(vec[i])]<0) cout<<abs(vec[i])<<endl;
        vec[abs(vec[i])]= vec[abs(vec[i])]*(-1);
    }
}

int main(){
    vector<int> vec = {1,5,2,3,7,5,4,1};
    getMultipleOccurances(vec);
}