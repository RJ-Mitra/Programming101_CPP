//Inverted triangle


#include<iostream>

using std::cin;
using std::cout;


int main()
{
    int numCols = 6;
    int numStars = 6;
    
    for(int i=0;i<numCols;i++){
        for(int j=i;j<numStars;j++){
            cout<<"#";
        }
        cout<<"\n";
    }

    return 0;
}
