//Solve Sudoku using backtracking
#include<bits/stdc++.h>
using namespace std;


void printBoard(vector<vector<int>>& vec){
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<vec[0].size();++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isSafeCol(vector<vector<int>>& vec, int col, int k){
    for(int row=0;row<9;++row){
        if(vec[row][col] == k) return false;
    }
    return true;
}

bool isSafeRow(vector<vector<int>>& vec, int row, int k){
    for(int col=0;col<9;++col){
        if(vec[row][col] == k) return false;
    }
    return true;
}

bool isSafeBox(vector<vector<int>>& vec, int boxFirstRow, int boxFirstCol, int k){
    for(int row=0;row<3;++row){
        for(int col=0;col<3;++col){
            if(vec[row+boxFirstRow][col+boxFirstCol] == k) return false;
        }
    }
    return true;
}

bool isSafe(vector<vector<int>>& vec, int row, int col, int k){
    if(vec[row][col] == 0 && isSafeRow(vec,row,k) && isSafeCol(vec,col,k) && isSafeBox(vec,row-row%3,col-col%3,k)) return true;
    return false;
}

bool nextUnassignedSlot(vector<vector<int>>& vec, int& row, int& col){
    for(row=0;row<9;row++){
        for(col=0;col<9;col++){
            if(vec[row][col] == 0) return true;
        }
    }
    return false;
}

bool solveSudoku(vector<vector<int>>& vec){
    int row, col;
    if(!nextUnassignedSlot(vec,row,col)){
        return true;
    }

    for(int n=1;n<=9;++n){
        if(isSafe(vec,row,col,n)){
            vec[row][col] = n;
            if(solveSudoku(vec)) return true;
            vec[row][col] = 0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> grid = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                                {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                                {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                                {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                                {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                                {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                                {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if(solveSudoku(grid)){
        printBoard(grid);
    }else{
        cout<<"No solution exists for given Sudoku"<<endl;
    }
}