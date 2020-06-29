//Tower of Hanoi
//Move n discs between 3 towers one at a time such that no larger disc is placed over a smaller disc

#include<iostream>
using namespace std;

void TOH(int n, int A, int B, int C){ // n-> no. of discs, A,B,C -> tower numbers
    if(n>0){
        TOH(n-1,A,C,B); //Move from tower A to tower B using tower C
        cout<<"Move from "<<A<<" to "<<C<<endl;
        TOH(n-1,B,A,C); //Move from tower B to tower C using tower A
    }
}

int main(){
    TOH(2,1,2,3);
}