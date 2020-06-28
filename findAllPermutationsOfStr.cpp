#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void printAllPerm(string str, int left, int right){
    if(left==right){ //base case. If left index becomes equal to right, we don't have any chars left to swap
        cout<<str<<endl; //print the string at that point
        return; //return to prev recursion scope
    }
    for(int i=left; i<=right;++i){ //for all seperate chars in the string
        swap(str[left],str[i]); //each iteration swaps char at left with the i value for that iteration
        printAllPerm(str,left+1,right); //1st char becomes fixed. We recursively call the str from the next char to the end char
        swap(str[left],str[i]); //backtrack to set the string to previous state after all permutations are found for that recursion stack
    }

}

int main(){
    string str = "ABC";
    int n = str.size();
    printAllPerm(str,0,n-1);
}




//Remove whitespaces from string in linear time and constant space

// #include<bits/stdc++.h>
// using namespace std;

// void getAllPerm(string str, int k, int n){
//     static int flag[10];
//     static char res[10];
//     if(str[k] == '\0'){
//         res[k] = '\0';
//         cout<<res<<endl; //base case
//     }else{
//         for(int i=0;i<n;++i){
//             if(flag[i] == 0){
//                 flag[i] = 1; //set flag to 1 denoting it is being used and move to the next char
//                 res[k] = str[i];
//                 getAllPerm(str,k+1,n);
//                 flag[i] = 0; //backtrack
//             }
//         }
//     }
// }

// int main(){
//     string str = "ABC";
//     getAllPerm(str,0,str.size());
// }
