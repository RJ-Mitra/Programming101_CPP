//Sieve of Eratosthenes

#include<bits/stdc++.h>
using namespace std;

vector<int> SieveOfEratosthenes(int n){
	bool isPrime[n+1];
	vector<int> primeList;
	memset(isPrime, true, sizeof(isPrime));

	for(int i=2; i*i<=n;i++){//Iterates over all numbers starting from 2 (1st prime)
		if(isPrime[i] == true){//If it is prime, marks all of its multiples as non-prime
			for(int j=i*i;j<n;j+=i){
				isPrime[j] = false;
			}
		}
	}

	for(int i=2;i<n;i++){
		if(isPrime[i]) primeList.push_back(i);
	}
	return primeList;
}


int main(){
	int n = 100;
	vector<int> result = SieveOfEratosthenes(n);
	for(int i:result) cout<<i<<endl;
}
