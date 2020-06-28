//Max contiguous array sum

//Using Kadane's algorithm

#include<bits/stdc++.h>
using namespace std;

// int getMaxSum(vector<int> inputVec){
//     int maxSum = 0;
//     int sum = 0;
//     int i=0;
//     while(i<inputVec.size()){
//         sum = max(inputVec[i] + sum, inputVec[i]);
//         maxSum = max(sum, maxSum);
//         ++i;
//     }
//     return maxSum;
// }

// int main(){
//     vector<int> inputVec = {-1,3,-5,6,14,9,7,-2,1,-4};
//     int res = getMaxSum(inputVec);
//     cout<<res<<endl;
// }



//Get least window which contains the all the elements to be searched

// bool isPresent(string searchStr, string toSearch){
//     for(int i=0; i<toSearch.size();++i){
//         size_t found = searchStr.find(toSearch[i]);
//         if(found==string::npos){
//             return false;
//         }
//     }
//     return true;
// }
// int getLeastWindow(string searchStr, string toSearch){
//     int i=0;
//     int j=0;
//     string str = "";
//     int leastSize = searchStr.size();
//     int currSize;
//     while(j<searchStr.size()){
//         str = searchStr[j];
//         //cout<<str<<endl;
//         while(!isPresent(str, toSearch) && j<searchStr.size()){
//             ++j;
//             str += searchStr[j];
//             cout<<"Appending: "<<str<<endl;
//         }
//         while(isPresent(str, toSearch)){
//             str = str.erase(0,1);
//             ++i;
//             cout<<"Erasing: "<<str<<endl;
//         }
//         currSize = j-i+1;
//         cout<<"CurrSize: "<<currSize<<endl;
//         leastSize = min(currSize, leastSize);
//         cout<<"LeastSize "<<leastSize<<endl;
//     }
//     return leastSize;
// }

// int main(){
//     // string searchString = "abdjksansibsajb";
//     // string toSearch = "bs";
//     string searchString = "azjskfzts";
//     string toSearch = "sz";
//     int res = getLeastWindow(searchString, toSearch);
//     //bool res = isPresent(searchString,toSearch);
//     cout<<res<<endl;
// }


//To find the 2nd largest element among a list of elements

//Tip: In any case of K-largest problems, best solution is a heap
//In case of K-largest, create a min heap and add all elements to heap upto k-largest and keep updating heap with each insertion

//Two pointer method

// int getSecondLargestTwoPointer(vector<int> inputVec){
//     int largest = -1000;
//     int second_largest = -1000;
//     for(int i=0;i<inputVec.size();++i){
//         if(inputVec[i] < largest && inputVec[i] > second_largest){
//             second_largest = inputVec[i];
//         }else if(inputVec[i] > second_largest && inputVec[i] > largest){
//             second_largest = largest;
//             largest = inputVec[i];
//         }
//     }
//     return second_largest;
// }

// int main(){
//     vector<int> inputVec = {-1,5,2,-3,7,5,1,7,9};
//     int res = getSecondLargestTwoPointer(inputVec);
//     cout<<res<<endl;
// }


//Heap method

// int getSecondLargestHeap(vector<int> inputVec){
//     priority_queue<int, vector<int>, greater<int>> min_heap;
//     for(int i=0;i<inputVec.size();++i){
//         min_heap.push(inputVec[i]);
//         if(min_heap.size()>2) min_heap.pop();
//     }
//     return min_heap.top();
// }


// int main(){
//     vector<int> inputVec = {-1,5,2,-3,7,5,1,7,9};
//     int res = getSecondLargestHeap(inputVec);
//     cout<<res<<endl;
// }


//K largest

// int getSecondLargestHeap(vector<int> inputVec, int k){
//     priority_queue<int, vector<int>, greater<int>> min_heap;
//     vector<int> seen;
//     for(int i=0;i<inputVec.size();++i){
//         vector<int>::iterator it = find(seen.begin(),seen.end(),inputVec[i]);
//         if(it == seen.end()){
//             min_heap.push(inputVec[i]);
//             if(min_heap.size()>k) min_heap.pop();
//             seen.push_back(inputVec[i]);
//         }
//     }
//     return min_heap.top();
// }


// int main(){
//     vector<int> inputVec = {-1,5,2,-3,7,5,1,7,9};
//     int k = 4; //Need 3rd largest element
//     int res = getSecondLargestHeap(inputVec,k);
//     cout<<res<<endl;
// }


//Increment an int array which stores the digits at each index
//e.g [1,2,9] -> [1,3,0]


// int main() {
// 	int inputArr[] = {9,9,9,9};
//     int n = sizeof(inputArr)/sizeof(inputArr[0]);
//     vector<int> result;
//     int initial_increment = 1;
//     int temp = 0;
//     int carry = 0;
//     for(int i=n-1;i>=0;--i){
//         temp = inputArr[i] + initial_increment + carry;
//         initial_increment = 0;
//         carry = 0;
//         if(temp>9){
//             carry = temp/10;
//             temp = temp%10;
//         }
//         result.push_back(temp);
//     }
//     if(carry!=0) result.push_back(carry);
//     reverse(result.begin(), result.end());
    
//     for(int i:result) cout<<i;
// }


/*Given an array of characters, compress them such that if there are
multiple occurances of same character, we return the total memory it
takes to compress it.

E.g. ['a'] -> return 1
     ['a','a','b','c','c','c'] -> return 5 ie. a2bc3 (length 5)
*/

// #include <bits/stdc++.h>
// using namespace std;


// int getCompressedCount(vector<char> inputVec){
//     int i=0;
//     int j=1;
//     string result_string = "";
//     while(j<inputVec.size()){
//         while(inputVec[i] == inputVec[j] && j<inputVec.size()){
//             ++j;
//         }
//         if(j-i>1){
//             result_string+=inputVec[i];
//             result_string+=to_string(j-i);
//         }else{
//             result_string+=inputVec[i];
//         }
//         i=j;
//         ++j;
//     }
//     cout<<result_string<<endl;
//     return result_string.size();
// }
// int main() {
//     vector<char> inputVec = {'a','b','b','b','b','b','b','b','b','b','b','b'};
// 	int res = getCompressedCount(inputVec);
// 	cout<<"Result: "<<res<<endl;
// }


/*Generate matching parantheses provided we are given an int as input
which is the number of possible pairs
*/

// #define MAX_SIZE 100
// //Recursive function
// void printParantheses(int pos, int n, int open, int close){
//     static char str[MAX_SIZE];
//     if(close == n){
//         cout<<str<<endl;
//         return;
//     }
//     if(close<open){
//         str[pos] = ')';
//         printParantheses(pos+1, n, open, close+1);
//     }
//     if(open<n){
//         str[pos] = '(';
//         printParantheses(pos+1, n, open+1, close);
//     }
// }


// //Driver
// int main(){
//     cout<<"Enter the number of pairs of parantheses required: "<<endl;
//     int n;
//     cin>>n;
//     if(n>0){
//         printParantheses(0,n,0,0);
//     }
// }


//N Queens problem

#include<bits/stdc++.h>
// using namespace std;

// #define N 4

// //Helper function to print board
// void printBoard(int board[N][N]){
//     for(int i=0;i<N;++i){
//         for(int j=0;j<N;++j){
//             cout<<" "<<board[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// //Utility function to determine if a placed queen is safe
// bool isSafe(int board[N][N], int row, int col){
//     int i=0,j=0;
//     //Check all spaces to the left for attacking queens since we are beginning from left-top part of the board and moving column wise. Column 0 is filled, then column 1 and so on...
//     for(i=0;i<N;++i){
//         if(board[row][i]) return false; //If any queen is found to the left
//     }
//     for(i=row,j=col;i>=0 && j>=0;i--,j--){
//         if(board[i][j]) return false; //If any queen is found along the upper left diagonal
//     }
//     for(i=row, j=col; i<N && j>=0;++i,--j){//If any queen is found along the lower left diagonal
//         if(board[i][j]) return false;
//     }
//     return true; //If no attacking queens are found, our queen is safe
// }

// bool solveNQ(int board[N][N], int col){
//     if(col>=N) return true;

//     for(int i=0;i<N;++i){
//         if(isSafe(board, i, col)){
//             board[i][col] = 1;

//             if(solveNQ(board,col+1)) return true;

//             board[i][col] = 0;
//         }
//     }

//     return false;
// }


// int main(){
//     int board[N][N] = { { 0, 0, 0, 0 }, 
//                         { 0, 0, 0, 0 }, 
//                         { 0, 0, 0, 0 }, 
//                         { 0, 0, 0, 0 } };
    
//     if(!solveNQ(board,0)) cout<<"No solution exists.";
//     else printBoard(board);
// }


// A board may have multiple battleships denoted by 'X' with spaces '.' between them.
//Find the number of battleships.

// #include<bits/stdc++.h>
// using namespace std;


// void display(vector<vector<char>> &vec){
//     for(int i=0;i<vec.size();++i){
//         for(int j=0;j<vec[0].size();++j){
//             cout<<" "<<vec[i][j];
//         }
//         cout<<endl;
//     }
// }


// void getAllShips(vector<vector<char>> &vec, int x, int y){
// 	if(x<0 || x>vec.size()-1 || y<0 || y>vec[0].size()-1 || vec[x][y] == '.') return;
//     vec[x][y] = '.';
//     getAllShips(vec, x-1, y);
// 	getAllShips(vec, x+1, y);
// 	getAllShips(vec, x, y-1);
// 	getAllShips(vec, x, y+1);
//     display(vec);
// }

// int getCountBattleships(vector<vector<char>> &vec){
// 	int count = 0;
// 	for(int i=0;i<vec.size();++i){
// 		for(int j=0;j<vec[0].size();++j){
//             cout<<" row :"<<i<<" col: "<<j<<endl;
// 			if(vec[i][j] == 'X'){
//                 count++;
// 				getAllShips(vec, i, j);
//                 //display(vec);
//                 cout<<"COUNT: "<<count<<endl;
// 			}
// 		}
// 	}
// 	return count;
// }

// int main(){
// 	vector<vector<char>> vec {{'X','.','.','X'},
// 		                      {'.','.','.','X'},
// 		                      {'.','.','.','X'},
// 		                      {'.','.','.','X'}};

// 	int res = getCountBattleships(vec);
// 	cout<<"Number of ships: "<<res<<endl;
// 	return 0;
// }


//Given list of integers where indexes are current position of people in a queue and values are their original
//positions in the queue before bribes. Each person can bribe the person ahead of them to take their position and
//advance up the queue. Find how many bribes were taken.

//Approach - Modified bubble sort

// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void display(vector<int> vec){
//     for(int i:vec) cout<<" "<<i<<" ";
//     cout<<endl;
// }

// int getCountBribes(vector<int> curr_queue){
//     int bribes = 0;
//     bool isSorted = false;
//     while(!isSorted){
//         isSorted = true;
//         for(int i=1;i<curr_queue.size();++i){
//             if(curr_queue[i] < curr_queue[i-1]){
//                 isSorted = false;
//                 ++bribes;
//                 swap(curr_queue[i],curr_queue[i-1]);
//                 display(curr_queue);
//             }
//         }
//     }
//     return bribes;
// }

// int main(){
//     int n = 5;
//     vector<int> curr_queue = {2,1,5,3,4};
//     //vector<int> curr_queue = {2,5,1,3,4};
//     //vector<int> curr_queue = {1,2,5,4,3};
//     //1 2 3 4 5 - original
//     //1 2 3 5 4
//     //1 2 5 3 4
//     //1 2 5 4 3
//     //vector<int> curr_queue = {3,1,5,2,7,6,4};
//     //1 2 3 4 5 6 7 - original
//     //1 3 2 4 5 6 7
//     //3 1 2 4 5 6 7
//     //3 1 2 5 4 6 7
//     //3 1 5 2 4 6 7
//     //3 1 5 2 4 7 6
//     //3 1 5 2 7 4 6
//     //3 1 5 2 7 6 4
//     int res = getCountBribes(curr_queue);
//     if(res==-1) cout<<"Too Chaotic"<<endl;
//     else cout<<"Number of bribes: "<<res<<endl;
// }