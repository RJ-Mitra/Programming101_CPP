#include<bits/stdc++.h>
using namespace std;

//LRU cache

//Given a list of page numbers and cache size, find the cache contents at
//the end of the process
//E.g. cache size 3 and list: 1 2 3 4 1 4 5 4. Cache: 4 5 1

class LRUCache{
    int cacheSize;
    list<int> cache_queue;
    unordered_map<int,list<int>::iterator> cache_map;
    public:
        LRUCache(int);
        void refer(int);
        void display();
};

LRUCache::LRUCache(int cacheSize){
    this->cacheSize = cacheSize;
}

void LRUCache::refer(int k){
    if(cache_map.find(k) == cache_map.end()){ //if the element is not present in the cache map
        if(cache_queue.size()==cacheSize){ //if the cache is full
            int last = cache_queue.back(); //we find the last element in the cache
            cache_queue.pop_back(); //and remove it from both cache
            cache_map.erase(last); //and cache map
        }
    }else{ //if the element is present in the cache, we remove its earlier position from the map
        cache_queue.erase(cache_map[k]); //from queue we delete the element based on the iterator from map
    }
    cache_queue.push_front(k);
    cache_map[k] = cache_queue.begin();
    //cout<<"page no.: "<<k<<" map val: "<<&*(cache_map[k])<<endl;
}

void LRUCache::display(){
    for(auto i:cache_queue){
        cout<<i<<" ";
    }
    cout<<endl;
}


int main(){
    LRUCache lru_c(3);
    int pages[] = {1,2,3,4,1,4,5,4};
    int n = sizeof(pages)/sizeof(pages[0]);
    for(int i=0;i<n;++i){
        lru_c.refer(pages[i]);
    }
    lru_c.display();
}