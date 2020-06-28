//Given a range of sorted distinct integers, return the ranges of the arrays

#include<bits/stdc++.h>
using namespace std;


void getRanges(vector<int> numList){
    int firstIndex = 0;
    int prevIndex = 0;
    int forwardIndex = 1;
    while(forwardIndex<=numList.size()){
        if(numList[prevIndex]+1 == numList[forwardIndex]){
            ++prevIndex; ++forwardIndex;
        }else{
            if(firstIndex != prevIndex){
                cout<<"Range: "<<numList[firstIndex]<<"->"<<numList[prevIndex]<<endl;
            }else{
                cout<<"Range: " <<numList[firstIndex]<<endl;
            }
            firstIndex = forwardIndex;
            prevIndex = forwardIndex;
            ++forwardIndex;
        }
    }
}

int main(){
    vector<int> numList = {-1,0,1,2,5,6,8,10,11,12,13,14,15,18,19};
    getRanges(numList);
}