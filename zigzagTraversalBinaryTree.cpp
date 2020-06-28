//Zigzag traversal of tree
/*
        1
    2       3
4         7   9

Zigzag traversal: 1 3 2 4 7 9
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left, *right;

        TreeNode(int data = -1){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

        ~TreeNode(){
            delete left;
            delete right;
        }
};

TreeNode* newNode(int data){
    TreeNode *node = new TreeNode(data);
    return node;
}

//void swap();

void zigZagTraversal(TreeNode* head){
    if(head==nullptr) return;
    
    bool leftToRight = true;
    stack<TreeNode*> current_level;
    stack<TreeNode*> next_level;
    TreeNode* node;

    current_level.push(head);
    while(!current_level.empty()){
        node = current_level.top();
        current_level.pop();
        if(node!=nullptr){
            cout<<node->data<<" ";
            if(leftToRight){
                if(node->left != nullptr) next_level.push(node->left);
                if(node->right != nullptr) next_level.push(node->right);
            }else{
                if(node->right != nullptr) next_level.push(node->right);
                if(node->left != nullptr) next_level.push(node->left);
            }
        }
        if(current_level.empty()){
            leftToRight = !leftToRight;
            current_level.swap(next_level);
        }  
    }
}


int main(){
    TreeNode *head = new TreeNode(1);
    TreeNode *node = nullptr;
    head->left = newNode(3);
    head->right = newNode(2);
    
    node = head->left;
    node->left = newNode(4);
    node->right = newNode(5);
    
    node = head->right;
    node->left = newNode(6);
    node->right = newNode(7);
    
    node=node->right;
    node->right = newNode(8);
    
    zigZagTraversal(head);
}