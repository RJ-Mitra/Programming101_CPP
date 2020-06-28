//Remove whitespaces from string in linear time and constant space

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "H ello! Thi s I s A Sp a ced St rin g.";
    int count = 0; //var to keep track of non-space chars
    for(int i=0;str[i];++i){
        if(str[i]!=' '){
            str[count] = str[i];
            count++;
        }
    }
    for(int i=0;i<count;++i){
        cout<<str[i];
    }
}
