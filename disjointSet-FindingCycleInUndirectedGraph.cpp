//Disjoint Set Data structure

//Disjoint Set is used with undirected graphs. It can be used in multiple
//scenarios including job sequencing and finding cycle in an undirected graph

//Find cycle with disjoint Set
//Given a list of from-to pairs signifying paths between vertices, find if the
//graph has a cycle


/*Approach:
    We use an array whose index is the set element and its value is the parent of the element.
    If an element is the root, its value is set to -1.
    Hence, 0 1 2 3
          -1 0 0 2
    means 0 is the root and parent of 1 and 2, and 2 is the parent of 3
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
        vector<int> dsuf;
    public:
        DisjointSet(int v){
            dsuf.resize(v,-1);
        }

        //find parent of the current set element
        int find(int c){
            if(dsuf[c] == -1) return c;
            return find(dsuf[c]);
        }

        //union of two sets
        void merge(int from, int to){
            from = find(from);
            to = find(to);
            dsuf[from] = to; //to is set as the parent of from
        }

        //find if graph has a cycle by comparing parent roots of from and to. If roots are same, graph has a cycle. Else we 
        bool isCyclic(vector<pair<int,int>> edgeList){
            for(auto e:edgeList){
                int from = find(e.first);
                int to = find(e.second);
                if(from==to) return true;
                merge(from,to);
            }
            return false;
        }

};

int main(){
    vector<pair<int,int>> edgeList = {{0,1},{2,3},{0,3},{1,2}};
    int n = edgeList.size();
    DisjointSet ds(n+1); //ds size should be equal to number of vertices
    if(ds.isCyclic(edgeList)) cout<<"Set has cycle.";
    else cout<<"Set has no cycle";
}


//See next code for optimisations (Path compression and union by rank)
