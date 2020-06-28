#include <bits/stdc++.h>
using namespace std;

//Callback func example

int add(int a, int b) 
{
    cout<<"Sum"<<endl;
    return a+b;
}

int sub(int a, int b){
    cout<<"Sub"<<endl;
    return a-b;
}
int mul(int a, int b){
    cout<<"Multiply"<<endl;
    return a*b;
}

int wrapper(int (*fun)(int,int), int a, int b){
    return fun(a,b);
}


int main() {
	int choice = 1;
    int a = 30;
    int b = 20;
	if(choice == 1){
	    cout<<wrapper(add,a,b)<<endl;
	}else if(choice == 2){
        cout<<wrapper(sub,a,b)<<endl;
    }else if(choice == 3){
        cout<<wrapper(mul,a,b)<<endl;
    }else{
        cout<<"Invalid Choice"<<endl;
    }
}
