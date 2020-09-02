//Given 2*n+2 numbers in an array where exactly 2 numbers are not in pair, find those 2 nums
//E.g 1,2,3,2,4,1 Ans: 3,4
//In GFG, test case output had to be in ascending


//NOTE: For finding single non-duplicate, we can use XOR.
/*
Properties of XOR:
x^x = 0
0^x = x
So, if we do an XOR of each element in the array, the remaining number will be the non-duplicate one

int nonDuplicate(int arr[], int n){
    int res = arr[0];
    for(int i=1;i<n;++i){
        res=res^arr[i]
    }
    return res;
}
*/

/*
For finding two non-duplicate elements,
we can do XOR of the array as shown above. This returns both the elements together in binary format.

We know that the XOR of the two non-duplicate elements will not be 0, 
since XOR gives 0 only for 1 XOR 1, and that can never happen since the
two numbers are not identical to each other (non-duplicate).

We partition the array into two parts. One set will have all elements of
array with kth bit turned to 1, while the other part will have all kth bits
turned off to 0.
Since xor or all duplicate elements will be 0 and the kth bit cannot be turned
on both in x and y (x and y are the two non-duplicate numbers), the two numbers
will be in different parts.
Each partition will have one of the non-duplicate numbers.
*/
#include<bits/stdc++.h>
using namespace std;

//Bit XOR approach (Most efficient)

//func to check if a given bit is set
bool hasBitSet(int n, int x){ //n-> number, x->number of places to left shift
    int temp = n&(1<<x); //AND of number with left shifted 1 will return true is bit is set
    return temp!=0;
}

void getNonPairedNums(int *arr, int n){
    int ans[2] = {0,0}; //array to store answer

    int res = arr[0]; //Find the xor of the entire array to find the two non-pair digits in binary
    for(int i=1;i<n;++i){
        res = res ^ arr[i];
    }

    int k = 0; //left-shift counter
    //Find the kth set bit by leftshifting the result until we find a turned bit
    while(hasBitSet(res,k) == 0) k++; //while not set, increase k (which results in more left shift)
    
    //now we know that the kth bit is set in res. So it will be set in one number, and not set in the other
    //from the main array we parition the two sets into kth bit on and off
    for(int i=0;i<n;++i){
        ans[hasBitSet(arr[i],k)] = ans[hasBitSet(arr[i],k)] ^ arr[i]; //if bit is set, the xor value will be stored in ans[true], i.e ans[1], otherwise in ans[0]
    }

    cout<<ans[0]<<" "<<ans[1]<<endl;
}

//ALT XOR method:

void getNonPairedNums(int *arr, int n){

    int res = arr[0]; //Find the xor of the entire array to find the two non-pair digits in binary
    for(int i=1;i<n;++i){
        res = res ^ arr[i];
    }

    int k = 0; //left-shift counter
    //Find the right most kth set bit by leftshifting the result until we find a turned bit
    while(hasBitSet(res,k) == 0) k++; //while not set, increase k (which results in more left shift)
    
    int digit1 = res;
    int digit2 = 0;
    
    //For each element in the main array having the kth bit set, 
    //we XOR them together with the XOR res to get digit 1
    for(int i=0;i<n;++i){
        if(hasBitSet(arr[i],k)){
            digit1=digit1^arr[i];
        }
    }
    //If we XOR digit1 with the res XOR value, we get digit 2
    digit2 = digit1^res;
    
    cout<<digit1<<" "<<digit2<<endl;
}


//Alternate approaches: Hashing, sort and find, stack

//Hashing approach:

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[(n+1)*2];
        for(int i=0;i<(n+1)*2;++i){
            cin>>arr[i];
        }
        map<int,int> count_map;
        for(int i=0;i<(n+1)*2;++i){
            if(count_map.find(arr[i]) == count_map.end()){
                count_map[arr[i]] = 1;
            }else{
                count_map[arr[i]]++;
            }
        }
        
        vector<int> res;
        int count = 2;
        for(auto i:count_map){
            if((i.second)%2!=0){
                res.push_back(i.first);
                count--;
            }
            if(count == 0) break;
        }
        sort(res.begin(),res.end());
        for(int i:res) cout<<i<<" ";
        cout<<endl;
    }
	//code
	return 0;
}


//Alternate approach

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> vec((n+1)*2,0);
        for(int i=0;i<(n+1)*2;++i){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        int j=0;
        while(j<(2*n+2)-1){
            if(vec[j] == vec[j+1]){
                j+=2;
            }else{
                cout<<vec[j]<<" ";
                j++;
            }
        }
        if(vec[j]!=vec[j-1]) cout<<vec[j];
        cout<<endl;
    }
	//code
	return 0;
}