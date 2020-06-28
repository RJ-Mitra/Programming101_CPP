/* Two arrays are given -> labels and values. Each index of labels has an integer number as the category
and the corresponding index of the values array has the value for that label.
E.g. labels = 1,2,2,3,1
     values = 7,9,2,5,6
where the values under label one are 7 and 6.
Also given are max_limit (limit of usage of values in each category) and num_wanted (number of total elements)
E.g. max_limit = 2 (Only 2 values from each category can be considered)
     num_wanted = 4 (Total 4 values can be considered.)

Need to find max sum of all valid elements.
*/


#include<bits/stdc++.h>
using namespace std;

struct Item{
    int label;
    int value;
    Item(int label, int value){
        this->label = label;
        this->value = value;
    }
};

// class comparator{
//     public:
//         int operator()(Item &a, Item &b){
//             return b.value > a.value;
//         }
// };


int getMaxSum(vector<int> labels, vector<int> values, int num_wanted, int use_limit){
    int max_sum = 0;
    auto compare = [](Item a,Item b){return b.value > a.value;}; //compare lambda for hax heap creation
    priority_queue<Item,vector<Item>,decltype(compare)> pq(compare); //max heap for values
    // priority_queue<Item,vector<Item>,comparator> pq; //Used with comparator class
    for(int i=0;i<labels.size();++i){
        pq.push(Item(labels[i],values[i]));
    }
    unordered_map<int,int> label_count; //map to keep track of each occurence of label
    while(!pq.empty() && num_wanted>0){
        Item i = pq.top(); //get label with the max value
        pq.pop();
        if(label_count.find(i.label) == label_count.end()){ //log count of the label
            label_count[i.label] = 1;
        }else{
            label_count[i.label]++; //increment count if already present
        }
        if(label_count[i.label]<=use_limit){ //if count is within specified limit
            max_sum+=i.value; //add to sum
            num_wanted--; //decrement number of elements required
        }
    }
    return max_sum;
}


int main(){
    vector<int> labels = {1,3,3,3,2};
    vector<int> values = {5,4,3,2,1};
    int num_wanted = 3;
    int use_limit = 1;
    int res = getMaxSum(labels,values,num_wanted,use_limit);
    cout<<res<<endl;
}