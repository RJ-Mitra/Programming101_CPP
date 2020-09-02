//Prim's algorithm

//Similar to Dijkstra's implementation

//Find MST using Prim's algorithm in a given undirected graph

#include<bits/stdc++.h>
using namespace std;

//function to find the minimum value node
int findMinVal(vector<int>& value, vector<bool>& processed){
    int min_val = INT_MAX;
    int min_val_index = -1;
    for(int i=0;i<value.size();++i){
        if(!processed[i] && value[i]<min_val){
            min_val = value[i];
            min_val_index = i;
        }
    }
    return min_val_index;
}

//function to find MST using Prim's algorithm
void getMSTPrim(vector<vector<int>>& graph){
    int V = graph.size();
    vector<int> parent(V,-1); //parent arr to track parent of each node
    vector<int> value(V,INT_MAX); //value arr to find weight of each node
    vector<bool> processed(V,false); //processed arr to track whether a node is processed
    value[0] = 0; //initially we set the starting node value as zero to begin the process
    for(int i=0;i<V-1;++i){ //for all edges (V-1)
        int U = findMinVal(value,processed); //find node with min val (0 in case of 1st iteration)
        processed[i] = true; //set the node to processed
        for(int j=0;j<V;++j){ //for all adjacent nodes in the graph
            if(graph[U][j]!=0 && !processed[j] && value[U]!=INT_MAX && graph[U][i] < value[j]){ //instead of adding path like in Dijkstra, we add check which path has lower weight from U to j
                value[j] = graph[U][j]; //we set the lower path wt as the new wt of the edge
                parent[j] = U; //we set the parent of the element
            }
        }
    }
    for(int i=1;i<V;++i){ //we print all paths
        cout<<"From "<<parent[i]<<" to "<<i<<": "<<graph[parent[i]][i]<<"\n";
    }
}

int main(){
    vector<vector<int>> graph = {{0,1,4,0,0,0},
                                 {1,0,4,2,7,0},
                                 {4,4,0,3,5,0},
                                 {0,2,3,0,4,6},
                                 {0,7,5,4,0,7},
                                 {0,0,0,6,7,0}};
    
    getMSTPrim(graph);
}