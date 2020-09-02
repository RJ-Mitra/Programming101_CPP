#include<bits/stdc++.h>
using namespace std;

/*
N people are sitting around a table in a circle. 
The first person kills the person next to him and hands the gun
to the person in the 3rd position and so on.
Who will the last person left alive


*** Tip to solve ***:
If a number is in the form 2^n (e.g. 16 -> 2^4), then the 1st person will
be the last one alive (since the gun moves alternatively)
For any number, we take the nearest number which is a perfect power of 2
and is lesser than the number.
E.g. if n = 9, we take 8, which is 2^3. Diff between them (l) = 9-8 = 1
The last surviving person is 2*l+1 -> 2*1+1 = 3

Explanation:
*****
*****
If the number is 21, it can be written as (2^n + l) (nearest perfect square less than n plus remaining part l)
21 -> 2^4 + 5 (hence, l = 5 here)
Therefore, l = 21 - 16 -> l = total persons - 2^n
l -> NUMBER OF STEPS REMAINING. The person alive after l steps wins
Each step involves 2 persons.
Hence 2*l -> number of persons to skip
2*l + 1 -> last person alive
*****
*****


*** Bit Trick ***:
If the number is expressed in binary, and we shift the 1st digit to the 
last, it gives us the number of the last person alive
E.g. n = 9
in binary: 1001
shifting 1st to last -> 0011 ->3
3 will be the last person alive

Implementation: Take binary digits in array. Left Rotate the binary array by 1
*/

int getLastPersonAlive(int totalPersons){
    int n = 1;
    while(n<totalPersons){ //finding power of 2 nearest to but less than total persons
        n*=2;
    }
    n/=2; //Going back by 2 since we overshot
    //n is a power of 2, and in a circle with 2^n people, the 1st person wins
    //total person - n gives us the number of steps left.
    //Since each step covers 2 people, we multiply by 2.
    //The next person after this (+1) is the last person alive
    int alive = 2*(totalPersons - n)+1;
    return alive;
}

int main(){
    int totalPersons = 100;
    cout<<getLastPersonAlive(totalPersons)<<endl;
}