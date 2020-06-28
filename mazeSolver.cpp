//Maze solver using backtracking and BFS

#include<bits/stdc++.h>
using namespace std;



void print(const vector<vector<int>>& maze){
    int N = maze.size();
    int M = maze[0].size();
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cout<<maze[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isSafe(vector<vector<int>>& maze, int i, int j){
    int N = maze.size();
    int M = maze[0].size();
    if(i>=0 && i<N && j>=0 && j<M && maze[i][j] == 1) return true;
    return false;
}

bool solveMaze(vector<vector<int>>& maze, int i, int j, vector<vector<int>>& sol){
    int N = maze.size();
    int M = maze[0].size();
    if(i==N-1 && j==M-1){
        sol[i][j] = 1;
        return true;
    }
    if(isSafe(maze,i,j)){
        sol[i][j] = 1;
        if(solveMaze(maze,i-1,j,sol)) return true;
        if(solveMaze(maze,i,j-1,sol)) return true;
        if(solveMaze(maze,i+1,j,sol)) return true;
        if(solveMaze(maze,i,j+1,sol)) return true;
        sol[i][j] = 0; //backtracking
        return false;
    }
    return false;
}

//wrapper
bool mazeSol(vector<vector<int>> &maze){
    int n = maze.size();
    vector<vector<int>> sol(n,vector<int>(n,0));
    if(solveMaze(maze,0,0,sol)){
        print(sol);
        return true;
    }
    return false;
}

int main(){
    vector<vector<int>> maze = {{1,0,1,1,1},
                                {1,1,1,0,1},
                                {1,0,0,1,1},
                                {1,1,0,1,0},
                                {0,1,0,1,1}};
    
    mazeSol(maze);
}