#include<bits/stdc++.h>
using namespace std;

/*Max fruits that can be picked using the two following actions:
1. Add one piece of fruit to the basket. if can't be added, stop.
2. Move to tree on the right. If no tree to the right, stop.

2 baskets are given. Each basket can carry only 1 type of fruit.
What is the max number of fruits that can be picked using this method?

E.g. {1,2,1} -> 3 fruits
{1,2,2,1,2,3,3,3,1,2,3} -> 5 fruits (1,2,2,1,2)
*/

// int getMaxFruits(vector<int> tree){
//     if(tree.size() == 0) return 0;
//     int i=0,j=0;
//     int map_size = 0;
//     int max_size = 1;
//     unordered_map<int,int> fruitMap;
//     while(j<tree.size()){
//         fruitMap[tree[j]] = j;
//         map_size = fruitMap.size();
//         //cout<<"Map size: "<<fruitMap.size()<<endl;
//         max_size = std::max(max_size, map_size);
//         if(fruitMap.size() > 2){
//             max_size = max(max_size, j-i);
//             i = fruitMap[tree[i]] + 1;
//             //cout<<"Erasing: "<<tree[i-1]<<endl;
//             fruitMap.erase(tree[i-1]);
//         }
//         j++;
//     }
//     return max_size;
// }


// //Sliding window approach
int getMaxFruits(vector<int> tree){
    int last_fruit = -1;
    int second_last_fruit = -2;
    int last_fruit_count = 0;
    int current_max = 0;
    int total_max = 0;

    for(int fruit:tree){
        if(fruit==last_fruit || fruit==second_last_fruit){
            ++current_max;
        }else{
            current_max = last_fruit_count+1;
        }

        if(fruit==last_fruit){
            ++last_fruit_count;
        }else{
            last_fruit_count = 1;
        }

        if(fruit!=last_fruit){
            second_last_fruit = last_fruit;
            last_fruit = fruit;
        }
        total_max = max(current_max,total_max);
    }
    return total_max;
}

int main(){
    vector<int> tree = {3,3,3,1,2,1,1,2,3,3,4};
    //vector<int> tree = {1,2,1};
    int res = getMaxFruits(tree);
    cout<<res;
}