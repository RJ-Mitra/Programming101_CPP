#include<iostream>

using std::cin;
using std::cout;

#define ROW 4
#define COLUMN 5

void islandCalc(int island[ROW][COLUMN], int i, int j){
    if(i<0 || i>=ROW || j<0 || j>=COLUMN || island[i][j] == 0){
        //Base case
        return;
    }else{
        island[i][j] = 0;
        //recursive call
        islandCalc(island,i+1,j);
        islandCalc(island,i-1,j);
        islandCalc(island,i,j+1);
        islandCalc(island,i,j-1);
    }
}


int main(){

    int islandCount = 0;
    int island[ROW][COLUMN] = {{1,1,1,0,0},
                               {1,1,0,0,0},
                               {1,0,0,1,1},
                               {0,1,0,0,1}};
    
    for (int i=0;i<ROW;i++){
        cout<<"\n";
        for(int j=0;j<COLUMN;j++){
            cout<<island[i][j];
        }
    }

    for (int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            if(island[i][j] == 1){
                islandCount++;
                islandCalc(island,i,j);
            }
        }
    }

    cout<<"\n";
    cout<<"Number of islands: ";
    cout<<islandCount;
}
