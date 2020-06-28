// //Get max product of each element in array except self (division allowed)
// #include<bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

// void getMaxProductButSelf(vector<int> inputVec){
//     int max_product = 1;
//     for(int i=0;i<inputVec.size();++i){
//         max_product*=inputVec[i];
//     }
//     vector<int> resVec(inputVec.size(),max_product);
//     for(int i=0;i<inputVec.size();++i){
//         resVec[i]=resVec[i]/inputVec[i];
//     }
//     for(int i:resVec) cout<<i<<endl;
    
// }

// int main(){
//     vector<int> inputVec = {5,4,3,2,1};
//     getMaxProductButSelf(inputVec);
// }

//Get max product of each element in array except self (division NOT allowed)
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

//Without division, the logic is to multiply the product of numbers to
//the left of the element with the product of numbers to the right of the element
void getMaxProductButSelf(vector<int> inputVec){
    //products to the left of each element
    vector<int> leftVec(inputVec.size());
    leftVec[0] = 1;
    for(int i=1;i<inputVec.size();++i){
        leftVec[i] = inputVec[i-1] * leftVec[i-1];
    }

    //products to the left of each element
    vector<int> rightVec(inputVec.size());
    rightVec[inputVec.size()-1] = 1;
    for(int i=inputVec.size()-2; i>=0;--i){
        rightVec[i] = inputVec[i+1] * rightVec[i+1];
    }

    //Product of both vectors
    vector<int> finalRes(inputVec.size());
    for(int i=0;i<inputVec.size();++i){
        finalRes[i] = leftVec[i]*rightVec[i];
    }
    
    //Printing result
    for(int i:finalRes) cout<<i<<endl;
}

int main(){
    vector<int> inputVec = {5,4,3,2,1};
    getMaxProductButSelf(inputVec);
}

//inputVec = 5 4 3 2 1
//leftVec =  1 5 20 60 120
//right vec = 24 6 2 1 1
