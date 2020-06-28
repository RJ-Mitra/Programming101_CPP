/* Find all occurances of element K in a sorted array.
Optimal solution.
*/
#include <bits/stdc++.h>
using namespace std;

enum searchType {FIRST, LAST};

int binarySearch(vector<int> &vec, int k, int left, int right, searchType type){
    if(vec.size()==0 || left>right) return -1;
    int mid = left+(right-left)/2;
    if(vec[mid] == k){
        if(type == FIRST){
            if(mid-1>=0 && vec[mid-1] == vec[mid]){
                return binarySearch(vec,k,left,mid-1,type);
            }
        }
        if(type == LAST){
            if(mid+1<=vec.size()-1 && vec[mid] == vec[mid+1]){
                return binarySearch(vec,k,mid+1,right,type);
            }
        }
        return mid;
    }else if(k<vec[mid]){
        return binarySearch(vec,k,left,mid-1,type);
    }else if(k>vec[mid]){
        return binarySearch(vec,k,mid+1,right,type);
    }
}


int findAllOccurances(vector<int> &vec, int k){
    int firstOccurence = binarySearch(vec,k,0,vec.size()-1,FIRST);
    if(firstOccurence == -1) return 0; //Returns at the start if no value is found
    int lastOccurence = binarySearch(vec,k,0,vec.size()-1,LAST);
    return lastOccurence - firstOccurence + 1;
}


int main(){
    vector<int> vec = {1,1,1,1,1,2,2,2,2,2,2,3,3,3,4,4,4,4,4,5,5};
    int k = 2;
    int res = findAllOccurances(vec,k);
    cout<<res<<endl;
}
