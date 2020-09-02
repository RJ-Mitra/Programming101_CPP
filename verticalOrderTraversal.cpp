//Vertical order traversal of binary tree

//Given a binary tree, display the nodes with same column number in order
//of their appearance in the tree (in order of level). If two nodes are in the same
//level and column, print them in ascending order.
//Assume root node is column number 0 and nodes to the left will be -1,-2
//and roots to the right will be 1,2, and so on.

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val):val{val},left{nullptr},right{nullptr}{}
};

//Approach 1: DFS - Using a map of map to store the nodes and their column numbers

void findVerticalOrders(TreeNode* curr, int row, int col, map<int,map<int,set<int>>>& orderMapSet){
    if(curr==nullptr){
        return;
    }
    orderMapSet[col][row].insert(curr->val); //col 1st, row 2nd since we took map of map of set to store the node values. 1st map will store cols, 2nd map will store nodes
    findVerticalOrders(curr->left,row+1,col-1,orderMapSet);
    findVerticalOrders(curr->right,row+1,col+1,orderMapSet);
}


vector<vector<int>> verticalOrderTraversal(TreeNode* root){
    map<int,map<int,set<int>>> orderMapSet;
    findVerticalOrders(root,0,0,orderMapSet);
    vector<vector<int>> res;
    for(auto m1: orderMapSet){
        res.push_back(vector<int>());
        for(auto m2: m1.second){
            for(auto m3: m2.second){
                res.back().push_back(m3);
            }
        }
    }
    return res;
}


//Approach 2: BFS - Using a queue (runs faster)

vector<vector<int>> findVerticalOrder_optimised(TreeNode* root){
    TreeNode* curr;
    vector<vector<int>> res; //resultant arr
    map<int,vector<int>> orderMap; //map of col order and vector which maps col order to the list of arrays in the same vertical column
    queue<pair<TreeNode*,int>> q; //queue for BFS //stores node and its col level
    q.push({root,0}); //pushing initial root node to queue with its col order as 0
    while(!q.empty()){ //while q is not empty, we go through each vertical level of the tree
        int size = q.size(); //we take size of q for each level, signifying number of nodes in each level
        map<int,set<int>> mapSet; //maps col to all nodes in that level. Using set to make sure same level nodes are in asc order
        while(size--){ //for each node in that level
            curr = q.front().first; //we take the node ptr
            int col = q.front().second; //we take the col order of that node
            q.pop(); //we remove the node from the queue
            mapSet[col].insert(curr->val); //we insert the node value into its col order map set
            if(curr->left!=nullptr){ //we recurse for left and right child nodes if they exist
                q.push({curr->left,col-1}); //we add the child node and its col order to the queue
            }
            if(curr->right!=nullptr){
                q.push({curr->right,col+1});
            }
        }
        for(auto it:mapSet){ //for all nodes in each level, we add it to the orderMap before moving on to the next level
            for(auto it2: it.second){ //this preserves the precedence of the nodes added
                orderMap[it.first].push_back(it2); //for each level (it.first), we store the val (it2) in that level map
            }
        }
    }
    for(auto it:orderMap){ //for all items in the orderMap, we store them in a list to print
        res.push_back(it.second);
    }
    return res;
}

//Driver code
int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    // vector<vector<int>> res = verticalOrderTraversal(root); //DFS
    vector<vector<int>> res = findVerticalOrder_optimised(root); //BFS
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    /*
    Tree shape:
                        0
                2               1
            5       6       3       4
    
    //Node 6 and 3 should be in the same vertical order
    */
}

