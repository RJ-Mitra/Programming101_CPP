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


/* OPTIMIZATIONS

1. Path compression:
        In find operation (to find parent root), update the parent of each element
        in the query with its parent element in the recursive call back, so that the
        next queries can directly find parent root instead of traversal.
2. Union by rank:
        When merging two sets, if we merge randomly, it can result in skewed tree structure,
        leading to slower lookup times. Instead, we can use a seperate rank variable in the disjoint
        set to store rank of each element and make the set with the higher rank
        as the parent of the set with the lower rank

*/

#include<bits/stdc++.h>
using namespace std;

class SetNode{
    public:
        int parent;
        int rank;
};

class DisjointSet{
    private:
        vector<SetNode> dsuf;
    public:
        DisjointSet(int v){
            dsuf.resize(v);
            for(int i=0;i<v;++i){
                dsuf[i].parent = -1;
                dsuf[i].rank = 0;
            }
        }

        //find parent of the current set element
        int find(int c){
            if(dsuf[c].parent == -1) return c;
            return dsuf[c].parent = find(dsuf[c].parent); //path compression (stores root parent of the set as parent of c)
        }

        //union BY RANK of two sets
        void merge(int from, int to){
            from = find(from);
            to = find(to);
            if(dsuf[from].rank > dsuf[to].rank) dsuf[to].parent = from; //if rank of from is greater than to, we add from as parent of to
            else if(dsuf[from].rank < dsuf[to].rank) dsuf[from].parent = to; //if rank of to is greater than from, we add to as parent of from
            else{ //if both ranks are same
                dsuf[from].parent = to; //we add any set as the parent of the other
                dsuf[to].rank+=1; //we increase the rank of the parent set (to) by 1
            }
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
    else cout<<"Set has no cycle.";
}


//See next code for optimisations (Path compression and union by rank)
