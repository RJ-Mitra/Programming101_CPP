//Code to get missing value among a series of numbers in an array (0 to n-1)
//where only 1 num is missing using Gauss' solution
//all numbers = n*(n+1)/2
#include<bits/stdc+.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected_sum = nums.size()*(nums.size()+1)/2;
        int res_sum = 0;
        for(int i=0;i<nums.size();++i){
            res_sum+=nums[i];
        }
        return expected_sum - res_sum;
    }
};


//Method 2
//E.g. [3,0,1]
/* nums.length = 3.
Iter 1:
 3+0
 3

 Iter 2:
 3+0+1
 3+0

 Iter 3:
 3+0+1+2 = 6
 3+0+1 = 4

Missing = 6-4 = 2
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected_sum = nums.size();
        int actual_sum = 0;
        for(int i=0;i<nums.size();++i){
            expected_sum+=i;
            actual_sum+=nums[i];
        }
        return expected_sum - actual_sum;
    }
};