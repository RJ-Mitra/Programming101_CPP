//Given a list integers, return true if the index of each duplicate falls within the distance of k from the previous one

#include<bits/stdc++.h>
using namespace std;


bool getDuplicateInterval(vector<int> numList, int k){
    unordered_map<int,int> indexMap;
    for(int i=0;i<numList.size();++i){
        if(indexMap.find(numList[i]) == indexMap.end()){
            indexMap[numList[i]] = i;
        }else{
            int prevIndex = indexMap[numList[i]];
            if(i - prevIndex > k ) return false;
            indexMap[numList[i]] = i;
        }
    }
    return true;
}

int main(){
    vector<int> numList = {1,3,5,1,2,5,9,8,7,5};
    int k = 3;
    bool isWithinThreshold = getDuplicateInterval(numList,k);
    cout<<isWithinThreshold<<endl;
}