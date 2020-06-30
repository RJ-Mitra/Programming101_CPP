//Given an even number, find two prime numbers whose sum equals to the given number
//Calculate Sieve Of Eratosthenes once and query the sieve table for each test case
//Max input range = 100000
//Goldback's conjecture: Every even integer greater than 2 can be expressed as the sum of two primes.

#include <bits/stdc++.h>
using namespace std;

//calculate sieve
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
	int t,input_num;
	cin>>t;
	while(t--){
	    cin>>input_num;
	    int i=2, j = input_num-2; //start summing primes from both ends
	    while(i<j){
	        if(!sieve[i]) ++i; //if not prime, move to next index in sieve array
	        if(!sieve[j]) --j; //if not prime, move to prev index in sieve array
	        if(sieve[i] && sieve[j] && i+j == input_num){ //if found, print the two primes
	            cout<<i<<" "<<j<<endl;
	            break;
	        }else if(i+j < input_num){ //if sum of i and j less than the input number, we need to increase the sum. So we increment the right pointer, since sieve is sorted
	            i++;
	        }else if(i+j > input_num){ //if sum of i and j is greater than input number, we decrement the right counter to decrease the sum, since sieve is sorted
	            j--;
	        }
	    }
	}
	return 0;
}