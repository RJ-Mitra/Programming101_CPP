//Serialize and deserealize a binary tree

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
    
    TreeNode(int val = 0){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* getNewNode(int val){
    TreeNode* node = new TreeNode(val);
    return node;
}

//pre-order traversal to serialize tree
void serialize(TreeNode* head, vector<int>& serialized){
    if(head==nullptr){ //base case
        cout<<"-1 ";
        serialized.push_back(-1);
        return;
    }
    cout<<head->val<<" ";
    serialized.push_back(head->val);
    serialize(head->left, serialized);
    serialize(head->right, serialized);
}

//vector to tree
TreeNode* deserialize(vector<int> &vec, int& k){ //k-> static counter for index
    if(k>=vec.size() || vec[k] == -1){
        ++k;
        return nullptr;
    }
    TreeNode* node = getNewNode(vec[k]);
    ++k;
    node->left = deserialize(vec,k);
    node->right = deserialize(vec,k);
    return node;
}

int main(){
    TreeNode* head = getNewNode(10);
    head->left = getNewNode(5);
    head->right = getNewNode(15);
    head->left->left = getNewNode(2);
    head->left->left->left = getNewNode(1);
    head->right->left = getNewNode(12);
    head->right->right = getNewNode(20);
    head->right->left->left = getNewNode(14);
    head->right->right->left = getNewNode(11);
    head->right->right->right = getNewNode(25);

    vector<int> serialized;
    serialize(head,serialized);
    cout<<"\n\n\n";
    int k = 0;
    vector<int> new_serialized;
    TreeNode* new_head = deserialize(serialized,k);
    serialize(new_head,new_serialized);
}