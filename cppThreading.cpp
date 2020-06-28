#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ll;

void getEven(ll start, ll stop){
    ll sum = 0;
    for(ll i=start;i<stop;++i){
        if(!(i&1)){
            sum+=i;
        }
    }
    cout<<"Even Sum: "<<sum<<"\n";
}

void getOdd(ll start, ll stop){
    ll sum = 0;
    for(ll i=start;i<stop;++i){
        if(i&1){
            sum+=i;
        }
    }
    cout<<"Odd Sum: "<<sum<<"\n";
}


int main(){
    ll begin = 1;
    ll end = 1900000000;

    auto start = high_resolution_clock::now();
    
    thread t1(getOdd,begin,end);
    thread t2(getEven,begin,end);
    
    t1.join();
    t2.join();
    
    
    // getEven(begin,end);
    // getOdd(begin,end);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout<<"Runtime: "<<duration.count()<<"\n";
}