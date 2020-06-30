/*Given an array A[] of N positive integers.
The task is to find the maximum of j - i subjected to the constraint
of A[i] <= A[j].

E.g. 

Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6

Explanation:
Testcase 1:  In the given array A[1] < A[7] satisfying the 
required condition(A[i] <= A[j]) thus giving the maximum difference 
of j - i which is 6(7-1).
*/

#include <iostream>
using namespace std;

int main() {
	//code
	int t,n,i,j;
	cin>>t;
	while(t--){
	    cin>>n;
	    int max_len = -1;
	    int arr[n];
	    for(int i=0;i<n;++i){
	        cin>>arr[i];
	    }
	    int L[n], R[n];
	    L[0] = arr[0];
	    for(int i=1;i<n;++i){
	        L[i] = min(arr[i],L[i-1]);
	    }
	    R[n-1] = arr[n-1];
	    for(int j=n-2;j>=0;--j){
	        R[j] = max(arr[j],R[j+1]);
	    }
	    i=0,j=0;
	    while(j<n && i<n){
	        if(L[i]<=R[j]){
	            max_len = max(max_len, j-i);
	            j++;
	        }else{
	            i++;
	        }
	    }
	    cout<<max_len<<endl;
	}
	return 0;
}