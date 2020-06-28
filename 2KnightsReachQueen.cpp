//Black and White Night
/*
Which knight reaches the queen first
*/

#include<bits/stdc++.h>
using namespace std;

struct Cell{
    int x, y;
    int color;
    int distance;
    Cell(){}
    Cell(int x, int y, int color, int dist):x{x},y{y},color{color},distance{dist}{}
};

bool isInBounds(int x, int y, int N){
    if(x>=0 && x<N && y>=0 && y<N) return true;
    return false;
}

int minimumSteps(int* knightWPos, int* knightBPos, int* queenPos, int N){
    queue<Cell> q;
    bool visitedW[N][N] = {false};
    bool visitedB[N][N] = {false};
    
    int x, y;
    Cell t;
    
    int dirX[8] = {-2,-2,2,2,1,-1,1,-1};
    int dirY[8] = {-1,1,-1,1,-2,-2,2,2};
    
    q.push(Cell(knightWPos[0],knightWPos[1],0,0));
    q.push(Cell(knightBPos[0],knightBPos[1],1,0));
    
    visitedW[knightWPos[0]][knightWPos[1]] = true;
    visitedB[knightBPos[0]][knightBPos[1]] = true;
    
    while(!q.empty()){
        t = q.front();
        q.pop();
        if(t.x == queenPos[0] && t.y == queenPos[1]){
            if(t.color) cout<<"Black wins";
            else cout<<"White wins";
            return t.distance;
        }
        for(int i=0;i<8;++i){
            x = t.x + dirX[i];
            y = t.y + dirY[i];
            
            if(t.color){
                if(isInBounds(x,y,N) && !visitedB[x][y]){
                    visitedB[x][y] = true;
                    q.push(Cell(x,y,t.color,t.distance+1));
                }
            }else{
                if(isInBounds(x,y,N) && !visitedW[x][y]){
                    visitedW[x][y] = true;
                    q.push(Cell(x,y,t.color,t.distance+1));
                }
            }
        }
    }
}

int main(){
    int boardSize = 30;
    int knightWPos[]={1,1};
    int knightBPos[]={5,5};
    int queenPos[]={29,29};
    cout<<"Minimum steps for knight to reach queen: "<<minimumSteps(knightWPos,knightBPos,queenPos,boardSize);
}
