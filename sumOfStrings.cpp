#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


string getSumOfStrings(string num1, string num2){
	if(num1.length()>num2.length()) swap(num1,num2);
	
	int num1_size = num1.length();
	int num2_size = num2.length();

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int sum = 0, carry = 0;
	string result = "";

	for(int i=0;i<num1_size;++i){
		sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		result.push_back((sum%10)+'0');
		carry = sum/10;
	}

	for(int i=num1_size;i<num2_size;++i){
		sum = (num2[i] - '0') + carry;
		result.push_back((sum%10)+'0');
		carry = sum/10;
	}

	if(carry) result.push_back(carry + '0');

	reverse(result.begin(), result.end());

	return result;
}

int main(){
	string num1 = "150";
	string num2 = "250";

	string result = getSumOfStrings(num1,num2);
	cout<<result<<endl;
}