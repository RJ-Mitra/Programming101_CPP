//Sorted list to binary search tree

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int value;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }

        TreeNode(int value, TreeNode *left, TreeNode *right){
            this->value = value;
            this->left = left;
            this->right = right;
        }
};

TreeNode* getNewNode(int val){
    TreeNode* newNode = new TreeNode(val);
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}


//Turn sorted list into binary search tree

TreeNode* getBstFromList(vector<int> vec, int left, int right){
    if(left>right) return nullptr;
    int mid = left + (right-left)/2;
    TreeNode* head = getNewNode(vec[mid]);
    head->left = getBstFromList(vec, left, mid-1);
    head->right = getBstFromList(vec, mid+1, right);
    return head;
}

void preOrder(TreeNode* head){
    if(head!=nullptr || head!=NULL){
        preOrder(head->left);
        cout<<" "<<head->value<<" ";
        preOrder(head->right);
    }
    return;
}

int main(){
    vector<int> sortedList = {-10,-5,-3,0,5,8,9};
    TreeNode* head = getBstFromList(sortedList,0,sortedList.size()-1);
    preOrder(head);
}