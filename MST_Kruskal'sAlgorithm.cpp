//Kruskal's algorithm

//Implementation of Kruskal's algorithm to find MST in an undirected graph

//Approach: The edge list is ordered in ascending order of their weights.
//For each edge, if adding the set doesn't form a cycle (cycle check using disjoint set)
//we add the edge in the MST and continue till we get V-1 edges (min edges in MST = V-1, V -> no. of vertices)

#include<bits/stdc++.h>
using namespace std;

//Edge class stores values from Adjacency matrix of graph
class Edge{
    public:
        int src;
        int dst;
        int wt;
};

//Vertex class tracks root parent of all elements in the set and rank
class Vertex{
    public:
        int parent;
        int rank;
};

//Disjoint Set class
class DisjointSet{
    vector<Vertex> dsuf;
    public:
        DisjointSet(int n){ //n is the number of vertices in the graph
            dsuf.resize(n);
            for(int i=0;i<n;++i){ //setting all initials parents to -1 and ranks to 0
                dsuf[i].parent = -1;
                dsuf[i].rank = 0;
            }
        }
        //function to find the root parent of a node in the disjoint set
        int find(int c){
            if(dsuf[c].parent == -1) return c;
            return dsuf[c].parent = find(dsuf[c].parent);
        }

        //function to merge two sets by rank
        void merge(int from, int to){
            int from_parent = find(from);
            int to_parent = find(to);
            if(dsuf[from_parent].rank > dsuf[to_parent].rank) dsuf[to_parent].parent = from_parent;
            else if(dsuf[from_parent].rank < dsuf[to_parent].rank) dsuf[from_parent].parent = to_parent;
            else{
                dsuf[from_parent].parent = to_parent;
                dsuf[to_parent].rank+=1;
            }
        }

        //find if an edge forms a cycle
        bool isCyclic(Edge e){
            int from = find(e.src);
            int to = find(e.dst);
            if(from == to) return true; //if the root of both sets are same, they form a cycle
            return false;
        }
};

//comparator to sort edges by ascending order of their weights
bool comparator(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}

//print the resultant MST
void printMST(vector<Edge>& mst){
    for(int i=0;i<mst.size();++i){
        cout<<"From: "<<mst[i].src<<" To: "<<mst[i].dst<<" MST wt: "<<mst[i].wt<<"\n";
    }
}

//Function to get From and To details from adjacency matrix (NOT REQUIRED HERE - ONLY FOR INFO)
void printAdjacencyInfo(vector<vector<int>>& graph){
    int V = graph.size();
    vector<Edge> edgeList;
    Edge temp;
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            temp.src = i;
            temp.dst = j;
            temp.wt = graph[i][j];
            if(temp.wt>0)
                edgeList.push_back(temp);
        }
    }
    for(int i=0;i<edgeList.size();++i){
        cout<<"From: "<<edgeList[i].src<<" To: "<<edgeList[i].dst<<" Wt: "<<edgeList[i].wt<<"\n";
    }
}

int main(){
    vector<vector<int>> graph = {{0,1,4,0,0,0},
                                 {1,0,4,2,7,0},
                                 {4,4,0,3,5,0},
                                 {0,2,3,0,4,6},
                                 {0,7,5,4,0,7},
                                 {0,0,0,6,7,0}}; //adjacency matrix of graph
    
    int V = graph.size(); //Number of vertices in the graph
    vector<Edge> edgeList; //list to store all edges in the graph
    Edge temp; //temp Edge to collect each edge details and insert into list
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            temp.src = i;
            temp.dst = j;
            temp.wt = graph[i][j];
            if(temp.wt>0) //if wt is 0, it means there is no connection between the nodes, hence it is not taken into account
                edgeList.push_back(temp);
        }
    }
    vector<Edge> mst; //vector to store only the mst graphs

    sort(edgeList.begin(),edgeList.end(),comparator); //edges sorted by asc order of their wts

    DisjointSet ds(V); //disjoint set ds to find cycles in graph

    int i=0,j=0;
    while(i<V-1 && j<edgeList.size()){ //We iterate till we reach V-1 edges (Each vertex connected only once)
        if(ds.isCyclic(edgeList[j])){ //if any edge results in a cycle, we skip it
            ++j;
            continue;
        }
        ds.merge(edgeList[j].src, edgeList[j].dst); //if not a cycle, we add the edge to our graph
        mst.push_back(edgeList[j]); //we add the edge to our MST
        ++i; //we increment the pointers
        ++j;
    }
    printMST(mst); //print the final MST
}