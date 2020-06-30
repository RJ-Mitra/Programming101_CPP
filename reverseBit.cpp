#include <iostream>
using namespace std;

//Reverse a bit and return value of reversed binary in int format
//E.g. input -> 1. Reverse of 1 with 31 leading zeroes is 100000000000000000000000000000000
//output -> 2147483648

int main() {
	int t, counter = 31; //counter to track number of zeros needed to the end of the result string
	unsigned int input_num, reversed_num;
	cin>>t; //for number of test cases
	while(t--){
	    cin>>input_num; //taking test case input
	    reversed_num = input_num;
	    input_num = input_num>>1; //shifting input number by 1 to right
	    while(input_num>0){
	        reversed_num = reversed_num<<1; //shifting result bit to left by 1 to insert the new digit
	        reversed_num = reversed_num|(input_num&1); //AND with input num returns 0 or 1 based on digit, and then OR with result inserts the new num is result
	        input_num = input_num>>1; //shifts to the next number in input num
	        counter--; //shift counter decreases by 1 (signifying number of zeros needed to the end of result string)
	    }
	    cout<<(reversed_num<<counter)<<endl;
	}
	return 0;
}


//Alternate

#include <iostream>
#include<algorithm>
#include<bitset>
using namespace std;

int main() {
	int t, counter = 31;
	unsigned int input_num, reversed_num;
	cin>>t;
	while(t--){
	    cin>>input_num;
	    string str;
	    str = bitset<32>(input_num).to_string(); //sets number to string in binary format
	    reverse(str.begin(),str.end()); //reverses the string
	    cout<<bitset<32>(str).to_ulong()<<endl; //converts binary string back to long
	}
	return 0;
}