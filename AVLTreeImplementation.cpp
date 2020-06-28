#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        //Constructors
        TreeNode(int val, int height = 1){
            setVal(val);
            setHeight(height);
            setLeft(nullptr);
            setRight(nullptr);
        }

        TreeNode(int val, TreeNode* left, TreeNode* right, int height = 1){
            setVal(val);
            setHeight(height);
            setLeft(left);
            setRight(right);
        }

        //Setters and getters
        int val(){
            return this->_val;
        }

        void setVal(int x){
            this->_val = x;
        }

        TreeNode* left(){
            return this->_left;
        }

        void setLeft(TreeNode* node){
            this->_left = node;
        }

        TreeNode* right(){
            return this->_right;
        }

        void setRight(TreeNode* node){
            this->_right = node;
        }

        int height(){
            return this->_height;
        }

        void setHeight(int h){
            if(h>=0){
                this->_height = h;
            }
        }

        ~TreeNode(){
            delete(_left);
            delete(_right);
        }

    private:
        int _val;
        TreeNode* _left;
        TreeNode* _right;
        int _height;
};


TreeNode* getNewNode(int val, int height=1){
    TreeNode* node = new TreeNode(val,height);
    return node;
}

int height(TreeNode* node){
    if(node==nullptr) return 0;
    return node->height();
}

int getBalance(TreeNode* node){
    if(node==nullptr) return 0;
    return height(node->left()) - height(node->right());
}

TreeNode* rightRotate(TreeNode* x){
    //Set left child of x (y) and right child of y (T2) - the two nodes whose links would change
    TreeNode* y = x->left();
    TreeNode* T2 = y->right();
    //Rotate - set right child of y(T2) to left child of x (old head). Is nullptr if no T2 exists.
    y->setRight(x);
    x->setLeft(T2);
    //Update heights
    y->setHeight(1+max(height(y->left()),height(y->right())));
    x->setHeight(1+max(height(x->left()),height(x->right())));
    //Return new root
    return y;
}

TreeNode* leftRotate(TreeNode* x){
    //Set right child of x (y) and left child of y (T2) - the two nodes whose links would change
    TreeNode* y = x->right();
    TreeNode* T2 = y->left();
    //Rotate - set left child of y(T2) to left child of x (old head). Is nullptr if no T2 exists.
    y->setLeft(x);
    x->setRight(T2);
    //Update heights
    y->setHeight(1+max(height(y->left()),height(y->right())));
    x->setHeight(1+max(height(x->left()),height(x->right())));
    //Return new root
    return y;
}

TreeNode* insert(TreeNode* node, int x){
    if(node==nullptr){//Base case for recursion
        return getNewNode(x);
    }
    //Insert
    if(x<node->val()){
        node->setLeft(insert(node->left(),x));
    }else if(x>node->val()){
        node->setRight(insert(node->right(),x));
    }else{
        return node;
    }
    //Update height after each recursive callback
    node->setHeight(1+max(height(node->left()), height(node->right()))); //Adds +1 for each level

    //Check balance after each recursive callback
    int balance = getBalance(node);

    //Perform rotations
    if(balance>1 && x<node->left()->val()){//balance>1 => sub-tree is left heavy. Right rotate.
        return rightRotate(node);
    }
    if(balance<-1 && x>node->right()->val()){//balance<1 => sub-tree is right heavy. Left rotate.
        return leftRotate(node);
    }
    if(balance>1 && x>node->left()->val()){//Left-Right rotate
        node->setLeft(leftRotate(node->left()));
        return rightRotate(node);
    }
    if(balance<-1 && x<node->right()->val()){//Right-Left rotate
        node->setRight(rightRotate(node->right()));
        return leftRotate(node);
    }
    return node;//If not unbalanced, return node without rotations
}

//To get in-order successor (smallest in right sub-tree) in a non-null bst
TreeNode* getMinValNode(TreeNode* node){
    TreeNode* current = node;
    while(current->left() != nullptr){
        current=current->left();
    }
    return current;
}

TreeNode* deleteNode(TreeNode* node, int x){
    //NORMAL BST DELETION
    if(node==nullptr) return node;
    if(x>node->val()){
        node->setRight(deleteNode(node->right(),x));
    }else if(x<node->val()){
        node->setLeft(deleteNode(node->left(),x));
    }else{ //if key is found, we first check for case where it has children nodes
        if((node->left() == nullptr) || (node->right() == nullptr)){
            TreeNode* temp = node->left() != nullptr ? node->left() : node->right();
            if(temp==nullptr){ //Both left and right child are null, i.e. no children
                temp = node;
                node = nullptr;
            }else{ //Has only 1 child which is set as the new node in place of deleted node
                *node = *temp; //Copying child node as the new node
                free(temp); //Child node is deleted from old place
            }
        }else{ //Having both left and right children
            TreeNode* temp = getMinValNode(node->right()); //Getting the in-order successor (min value of right node)
            node->setVal(temp->val()); //Copying inorder successor data to node as new node value
            node->setRight(deleteNode(node->right(), temp->val())); //Deleting the child node which replaced the root node in last step
        }
    }
    if(node==nullptr) return node; //After setting node to new node, if node is null

    //UPDATING TREE HEIGHT AND CHECKING BALANCE
    node->setHeight(1+max(height(node->left()), height(node->right())));

    int balance = getBalance(node);

    //BALANCING THE TREE IF UNBALANCED
    if(balance>1 && x<node->left()->val()){
        return rightRotate(node);
    }
    if(balance<-1 && x>node->right()->val()){
        return leftRotate(node);
    }
    if(balance>1 && x>node->left()->val()){
        node->setLeft(leftRotate(node->left()));
        return rightRotate(node);
    }
    if(balance<-1 && x<node->right()->val()){
        node->setRight(rightRotate(node->right()));
        return leftRotate(node);
    }
    return node;
}


void displayBST(TreeNode* node){
    if(node==nullptr) return;
    displayBST(node->left());
    cout<<"Value: "<<node->val()<<" | Height: "<<node->height()<<" | Location: "<<node<<" ||"<<endl;
    displayBST(node->right());
}

// TreeNode* insert(TreeNode* head, int x){
//     TreeNode* temp = head;
//     TreeNode* prev = nullptr;
//     if(temp==nullptr){
//         temp = getNewNode(x);
//         return temp;
//     }
//     while(temp!=nullptr){
//         if(x==temp->val()) return temp;
//         prev = temp;
//         if(x<temp->val()) temp=temp->left();
//         else if(x>temp->val()) temp=temp->right();
//     }
//     TreeNode* newNode = getNewNode(x,prev->height()+1);
//     newNode->setLeft(nullptr);
//     newNode->setRight(nullptr);
//     if(x<prev->val()) prev->setLeft(newNode);
//     else if(x>prev->val()) prev->setRight(newNode);
//     return newNode;
// }

//Search AVL tree
void search(TreeNode* head, int x){
    if(head==nullptr) return;
    if(head->val() == x){
        cout<<"Value "<<x<<" found at location "<<head<<"."<<endl;
        return;
    }
    if(x>head->val()) return search(head->right(),x);
    else if(x<head->val()) return search(head->left(),x);
    cout<<"Element "<<x<<" is not present in the BST."<<endl;
}

// void displayBST(TreeNode* head){
//     if(head==nullptr) return;
//     cout<<"Value: "<<head->val()<<" | Height: "<<head->height()<<" | Location: "<<head<<" || \n";
//     displayBST(head->left());
//     displayBST(head->right());
// }


int main(){
    TreeNode *head = getNewNode(10);
    insert(head,5);
    insert(head,15);
    insert(head,3);
    insert(head,6);
    insert(head,14);
    insert(head,17);
    insert(head,6);

    displayBST(head);
    
    deleteNode(head, 14);
    
    cout<<"\n\nAfter deletion: \n\n";
    displayBST(head);
}