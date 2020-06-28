//A number is happy if the sum of the square of its digits eventually become 0

#include<bits/stdc++.h>
using namespace std;

bool ishappyNum(int n){
	std::unordered_set<int> seen;
	std::unordered_set<int>::iterator it;
	while(n!=1){
		int current = n;
		int sum = 0;
		while(current!=0){
			sum += ((current%10)*(current%10));
			current/=10;
		}
		it = seen.find(sum);
		if(it != seen.end()){
			return false;
		}
		seen.insert(sum);
		n=sum;
	}
	return true;
}

int main(){
	int n;
	cout<<"Enter a number to check if it's happy: ";
	cin>>n;
	bool isHappy = ishappyNum(n);
	if(isHappy) cout<<n<<" is a happy number."<<endl;
	else cout<<n<<" is not happy number."<<endl;
}
