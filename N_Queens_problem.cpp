#include <bits/stdc++.h>
using namespace std;


void print_board(vector<vector<int>>& board){
    cout<<"\n--------------------\n";
    int b_size = board.size();
    for(int i=0;i<b_size;++i){
        for(int j=0;j<b_size;++j){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}


bool isSafe(vector<vector<int>>& board, int row, int col){
    //Check all columns to the left
    int i,j;
    for(i=0;i<col;++i){
        if(board[row][i]) return false;
    }
    for(i=row,j=col;i>=0 && j>=0;--i,--j){
        if(board[i][j]) return false;
    }
    for(i=row,j=col;i<board.size() && j>=0;++i,--j){
        if(board[i][j]) return false;
    }
    return true;
}


bool NQueenUtil(vector<vector<int>>& board, int col){
    if(col>=board.size()) return true;
    for(int i=0;i<board.size();++i){
        if(isSafe(board,i,col)){
            board[i][col] = 1;
            if(NQueenUtil(board,col+1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}


int main() {
	int n;
	cin>>n;
	vector<vector<int>> board(n,vector<int>(n,0));
	print_board(board);
	if(NQueenUtil(board,0)) print_board(board);
	else cout<<"No solutions possible";
}

//All solutions

// #include <bits/stdc++.h>
// using namespace std;


// void print_board(vector<vector<int>>& board){
//     cout<<"\n--------------------\n";
//     int b_size = board.size();
//     for(int i=0;i<b_size;++i){
//         for(int j=0;j<b_size;++j){
//             cout<<board[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     cout<<"\n--------------------\n";
// }


// bool isSafe(vector<vector<int>>& board, int row, int col){
//     //Check all columns to the left
//     int i,j;
//     for(i=0;i<col;++i){
//         if(board[row][i]) return false;
//     }
//     for(i=row,j=col;i>=0 && j>=0;--i,--j){
//         if(board[i][j]) return false;
//     }
//     for(i=row,j=col;i<board.size() && j>=0;++i,--j){
//         if(board[i][j]) return false;
//     }
//     return true;
// }


// bool NQueenUtil(vector<vector<int>>& board, int col){
//     if(col==board.size()){
//         print_board(board);
//         return true;
//     }
//     bool res = false;
//     for(int i=0;i<board.size();++i){
//         if(isSafe(board,i,col)){
//             board[i][col] = 1;
//             res = NQueenUtil(board,col+1) || res;
//             board[i][col] = 0;
//         }
//     }
//     return res;
// }


// int main() {
// 	int n;
// 	cin>>n;
// 	vector<vector<int>> board(n,vector<int>(n,0));
// 	NQueenUtil(board,0);
// }
