//Find all prime numbers between two given ranges
//Calculate Sieve Of Eratosthenes once and query the sieve table for each test case
//Max input range = 100000

#include <bits/stdc++.h>
using namespace std;


void sieveOfEratosthenes(int num, vector<bool>& sieve){
    for(int i=2;i*i<=num;++i){
        if(sieve[i]){
            for(int j=i*i;j<num;j+=i){
                sieve[j] = false;
            }
        }
    }    
}

int main() {
	//code
	int num = 100000;
	vector<bool> sieve(num+1,true);
	sieveOfEratosthenes(num,sieve);
	int t,l,u;
	cin>>t;
	while(t--){
	    cin>>l>>u;
	    if(l==1) l = 2;
	    for(int i=l;i<=u;++i){
	        if(sieve[i]) cout<<i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}