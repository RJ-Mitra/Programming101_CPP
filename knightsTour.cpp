//Knight's Tour
//Each square of a board must be visited only once by a knight
//If solution exists, print board

#include <bits/stdc++.h>
using namespace std;

#define N 8

void printBoard(int sol[N][N]){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isSafe(int x, int y, int sol[N][N]){
    if(x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1) return true;
    return false;
}

int solveKT(int x, int y, int move_num, int sol[N][N], int *dirX, int *dirY){
    if(move_num == N*N) return 1; //base case. If move number is equal to number of squares in board, all squares are filled
    int next_x, next_y;
    for(int i=0;i<8;++i){
        next_x = x + dirX[i]; //calculate next moves for knight
        next_y = y + dirY[i];
        if(isSafe(next_x,next_y,sol)){ //check if next move is within bounds
            sol[next_x][next_y] = move_num; //set the valid move with current move number
            if(solveKT(next_x,next_y,move_num+1,sol,dirX,dirY)) return 1; //recursively check if the move is valid
            else sol[next_x][next_y] = -1;// if move is not valid, backtrack and set sol matrix to -1 for that index
        }
    }
    return 0; //if no solutions are possible, return 0
}

int main() {
	int sol[N][N]; //initially set sol matrix to -1
	for(int i=0;i<N;++i){
	    for(int j=0;j<N;++j){
	        sol[i][j] = -1;
	    }
	}
	
	int dirX[8] = { 2,1,-1,-2,-2,-1,1,2}; 
    int dirY[8] = { 1,2,2,1,-1,-2,-2,-1}; 
    
	sol[0][0] = 0; //set first position of the knight to move number 0 and start tour
	if(solveKT(0,0,1,sol,dirX,dirY) == 0) cout<<"No solutions."<<endl;
	else printBoard(sol);
	
}
