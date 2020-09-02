//Dijkstra's algorithm

//Dijkstra's algorithm to find the shortest path to all nodes of an undirected graph

#include<bits/stdc++.h>
using namespace std;

//function to get the vertex which has minimum value and is yet unprocessed
int getMinVertex(vector<int>& value, vector<int>& processed){
    int min_val = INT_MAX;
    int min_val_vertex = 0;
    for(int i=0;i<value.size();++i){
        if(!processed[i] && value[i]<min_val){
            min_val = value[i];
            min_val_vertex = i;
        }
    }
    return min_val_vertex;
}

//function to get least paths to each node from starting node
void getPathDijkstra(vector<vector<int>>& graph){
    int V = graph.size();
    vector<int> parent(V,-1); //parent vector to keep track of least wt parent of each node
    vector<int> value(V,INT_MAX); //vector to keep track of weights of least path between vertices (value of all points are infinity (INT_MAX) at start)
    vector<int> processed(V,false); //vector to keep track of processed vertices (all are not processed at beginning)
    value[0] = 0; //value of origin vertex is initialized to 0 as starting point
    for(int i=0;i<V-1;++i){ //for all edges (V-1) [U-> current vertex, j-> adjacent vertices]
        int U = getMinVertex(value,processed); //get the unprocessed vertex with the minimum value (will take up 0 or starting node during 1st iteration)
        processed[U] = true; //set its processed flag as true
        for(int j=0;j<V;++j){ //for all adjacent vertices to the current vertex
            if(graph[U][j]!=0 && !processed[j] && value[U]!=INT_MAX && (graph[U][j]+value[U]<value[j])){ //if the vertex is adjacent (graph val != 0) and not processed and the current vertex value is not infinity and the wt of current vertex + edge wt is lesser than the adjacent vertex
                value[j] = value[U]+graph[U][j]; //we update (relax) the value of the adjacent vertex
                parent[j] = U; //we set the current vertex as the parent of the adjacent vertex
            }
        }
    }
    for(int i=1;i<V;++i){ //print all least paths from origin to all nodes
        cout<<"U->V: "<<parent[i]<<" -> "<<i<<" wt= "<<graph[parent[i]][i]<<"\n"; //parent[i] gives path from least path parent to the current element
    }
}

int main(){
    vector<vector<int>> graph = {{0,1,4,0,0,0},
                                 {1,0,4,2,7,0},
                                 {4,4,0,3,5,0},
                                 {0,2,3,0,4,6},
                                 {0,7,5,4,0,7},
                                 {0,0,0,6,7,0}};
    
    getPathDijkstra(graph);
}