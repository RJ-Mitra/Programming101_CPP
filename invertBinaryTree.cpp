//Invert a binary tree (mirror image)

//Given a binary tree, invert it such that the right nodes become left nodes and vice-versa
/*
Example:
        1                       1
    2       3      ->       3       2
  4   5   6    7          7   6   5    4 
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val):value{val},left{nullptr},right{nullptr}{}
};

//function to invert binary tree
TreeNode* invert_binarytree(TreeNode* head){
    if(head==nullptr) return nullptr;
    TreeNode* temp = nullptr;
    invert_binarytree(head->left); //invert left sub-tree
    invert_binarytree(head->right); //invert right sub-tree
    temp = head->left; //swap the left node with the right node after recursive call ends
    head->left = head->right;
    head->right = temp;
    return head;
}

void preorder_print(TreeNode* head){
    if(head==nullptr) return;
    cout<<head->value<<" ";
    preorder_print(head->left);
    preorder_print(head->right);
}

void inorder_print(TreeNode* head){
    if(head==nullptr) return;
    preorder_print(head->left);
    cout<<head->value<<" ";
    preorder_print(head->right);
}

int main(){
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);

    preorder_print(head);
    cout<<"\n\n";
    TreeNode* inverted_head = invert_binarytree(head);
    preorder_print(inverted_head);
}