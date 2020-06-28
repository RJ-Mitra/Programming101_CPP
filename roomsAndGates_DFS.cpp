#include<bits/stdc++.h>
using namespace std;

//Given a n x n 2D grid with 3 possible values,
// -1 -> a wall or obstacle
//  0 -> a gate
// INF-> an empty room. (We use value 2^31-1 to represent INF. Assume all distances to be less than this.)

//Fill each room with the distance to its nearest gate. If it is impossible to reach a gate, it should be equal to INF.


/* 

Sample input:

INF   -1      0    INF
INF   INF    INF   -1
INF   -1     INF   -1
0     -1     INF   INF

Sample output:

3  -1   0   1
2   2   1  -1
1  -1   2  -1
0  -1   3   4

*/


void dfs(vector<vector<int>> &grid, int i, int j, int count){
	if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] < count){
		return;
	}
	grid[i][j] = count;
	dfs(grid, i+1, j, count+1);
	dfs(grid, i, j+1, count+1);
	dfs(grid, i-1, j, count+1);
	dfs(grid, i, j-1, count+1);
}

void getDistanceFromGate(vector<vector<int>> &grid){
	for(int i=0;i<grid.size();++i){
		for(int j=0;j<grid[0].size();++j){
			if(grid[i][j] == 0)
			dfs(grid,i,j,0);
		}
	}
}

int main(){
	vector<vector<int>> grid = {{100,   -1,      0,    100},
								{100,   100,    100,   -1 },
								{100,   -1,     100,   -1 },
								{0,     -1,     100,   100}};
	
	getDistanceFromGate(grid);

	for(int i=0;i<grid.size();++i){
		cout<<"{"<<endl;
		cout<<"{";
		for(int j=0;j<grid[0].size();++j){
			cout<<grid[i][j]<<",";
		}
		cout<<"}"<<endl;
	}
}