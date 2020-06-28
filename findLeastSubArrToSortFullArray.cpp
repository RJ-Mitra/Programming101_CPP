/*Given a list of numbers, find smallest the sub-array, which if sorted,
will lead to the entire list getting sorted. Return length of the sub-array

Approach 1: Sort the list and compare both lists. The part which is not
matching is the required sub-array that needs to be sorted.

Approach 2: (below) Find the least number which is in unsorted position
from the left as well as the max number which is in unsorted position from
the right. Then find and substract their original positions in the array
from left and right and find the index difference between those two.
*/

#include <bits/stdc++.h>
using namespace std;

int getLenUnsortedPart(vector<int> vec){
    int min_elm = 1000;
    int max_elm = -1000;
    //Finding the least unsorted element from left side
    for(int i=1;i<vec.size();++i){
        if(vec[i]<vec[i-1]){
            min_elm = min(min_elm,vec[i]);
        }
    }
    //Finding the max unsorted element from right side
    for(int i=vec.size()-2;i>=0;--i){
        if(vec[i]>vec[i+1]){
            max_elm = max(max_elm, vec[i]);
        }
    }
    int l=0, r=vec.size()-1;
    while(l<vec.size()){
        if(vec[l] > min_elm) break;
        ++l;
    }
    while(r>=0){
        if(vec[r] < max_elm) break;
        --r;
    }
    if(r-l<0) return 0;
    return r-l+1;
}


int main(){
    vector<int> vec = {-1,2,6,4,8,10,9,14,15};
    int res = getLenUnsortedPart(vec);
    cout<<"Length of unsorted part: "<<res<<endl;
}