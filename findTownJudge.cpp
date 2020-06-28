//Find the Town Judge based on trust values. Input has an array of sub-arrays.
//Each sub-array has the trust values of that individual.
//E.g. [[2,3],[1,3]], so 3 is the judge since he is trusted by both 2 and 1.
//The judge is trusted by everyone but trusts no-one.
//Other citizens may or may not trust each other.

#include<bits/stdc++.h>
using namespace std;

int getTownJudge(vector<vector<int>> trustVec){
    vector<int> trustCount(trustVec.size()+1,0); //Extra 1 space since we cannot use index 0 (no person labelled 0)
    for(vector<int> person : trustVec){
        trustCount[person[0]]--; //If person trusts someone, his counter decreases
        trustCount[person[1]]++; //The counter of the trusted person increases
    }
    
    for(int i=1;i<trustCount.size()+1;++i){ //There is no person 0, hence starting from 1
        if(trustCount[i] == (trustCount.size()-1)){ //If the person has everyone's trust
            return i; //He is the judge
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> trustVec = {{1,3},{2,3}};
    int res = getTownJudge(trustVec);
    if(res==-1) cout<<"No judge found"<<endl;
    else cout<<"The judge is: "<<res<<endl;
}