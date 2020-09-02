//Bellman Ford algorithm

//Similar to Dijkstra's algorithm for finding shortest path in a graph,
//but can handle negative edge weights also in directed graphs

#include<bits/stdc++.h>
using namespace std;


//Edge class stores values from Adjacency matrix of graph
class Edge{
    public:
        int src;
        int dst;
        int wt;
};

//function to get least paths to each node from starting node
void bellmanFordShortestPath(vector<Edge>& edgeList, int V){
    int E = edgeList.size();
    vector<int> parent(V,0);
    vector<int> value(V,INT_MAX);
    parent[0] = -1;
    value[0] = 0;
    //bool updated;
    for(int i=0;i<V-1;++i){
        //updated = false;
        for(int j=0;j<E;++j){
            int U = edgeList[j].src;
            int V = edgeList[j].dst;
            int wt = edgeList[j].wt;
            if(value[U]!=INT_MAX && value[U]+wt<value[V]){
                value[V] = value[U]+wt;
                parent[V] = U;
                //updated = true;
            }
        }
        //if(!updated) break;
    }

    //We repeat this in order to find negative edge weights (if any of previously found wts are decreasing, we know that edge has -ve wt)
    for(int j=0;j<E;++j){
        int U = edgeList[j].src;
        int V = edgeList[j].dst;
        int wt = edgeList[j].wt;
        if(value[U]!=INT_MAX && value[U]+wt<value[V]){
            cout<<"Graph has negative edge cycle.";
            return;
        }
    }

    //printing distances from 0 to all vertices
    for(int i=1;i<V;++i){
        cout<<"U->V: 0"<<"->"<<i<<" Cost to reach: "<<value[i]<<"\n";
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
            if(temp.wt!=0) //if wt is 0, it means there is no connection between the nodes, hence it is not taken into account
                edgeList.push_back(temp);
        }
    }
    
    bellmanFordShortestPath(edgeList,V);
}
