//Minimum steps
/*
Minimum number of steps required for the knight to strike the queen
*/

#include<bits/stdc++.h>
using namespace std;

struct Cell{
    int x, y;
    int distance;
    Cell(){}
    Cell(int x, int y, int dist):x{x},y{y},distance{dist}{}
};

bool isInBounds(int x, int y, int N){
    if(x>=1 && x<=N && y>=1 && y<=N) return true;
    return false;
}

int minimumSteps(int* knightPos, int* queenPos, int N){
    queue<Cell> q;
    bool visited[N+1][N+1] = {false};
    
    int x, y;
    Cell t;
    
    int dirX[8] = {-2,-2,2,2,1,-1,1,-1};
    int dirY[8] = {-1,1,-1,1,-2,-2,2,2};
    
    q.push(Cell(knightPos[0],knightPos[1],0));
    visited[knightPos[0]][knightPos[1]] = true;
    while(!q.empty()){
        t = q.front();
        q.pop();
        if(t.x == queenPos[0] && t.y == queenPos[1]) return t.distance;
        for(int i=0;i<8;++i){
            x = t.x + dirX[i];
            y = t.y + dirY[i];
            
            if(isInBounds(x,y,N) && !visited[x][y]){
                visited[x][y] = true;
                q.push(Cell(x,y,t.distance+1));
            }
        }
    }
}

int main(){
    int boardSize = 30;
    int knightPos[]={1,1};
    int queenPos[]={30,30};
    cout<<"Minimum steps for knight to reach queen: "<<minimumSteps(knightPos,queenPos,boardSize);
}
