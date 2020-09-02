//Doctors and patients
//42
//2222
//1323
//Answer: 8

#include<bits/stdc++.h>
using namespace std;

int findLeast(vector<vector<int>>& vec){
    int min_effort = 0;
    int sum = 0;
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[0].size();++j){
            sum+=vec[i][j];
        }
        min_effort = min(min_effort,sum);
    }
}

int minimumTime(int x, int y, vector<vector<int>> sol, int doc_no){
    int least = INT_MAX;
    if(x == vec.size() && y == vec[0].size()){
        int least = findLeast(sol);
    }
}