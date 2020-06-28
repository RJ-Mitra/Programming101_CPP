#include<bits/stdc++.h>
#include "minHeap.h"
using namespace std;

int main(){
    MinHeap h(11); 
    h.insert(3); 
    h.insert(2); 
    h.deleteKey(1); 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    cout << h.pop() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
}