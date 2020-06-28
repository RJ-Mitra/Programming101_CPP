//Linked List all

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* getNewNode(int data){
            Node* node = new Node;
            node->data = data;
            node->next = nullptr;
            return node;
        }

void insert(Node* head, int data){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next = getNewNode(data);
    temp->next->next = nullptr;
}

void printList(Node* head){
    if(head==nullptr){
        cout<<"Linked List is empty."<<endl;
        return;
    }
    int counter = 0;
    Node* temp = head;
    while(temp!=nullptr){
        ++counter;
        cout<<"Link "<<counter<<" node: "<<temp<<". Data: "<<temp->data<<endl;
        temp=temp->next;
    }
    //Intentionally not printing the head node
}

void printList_recursive(Node* head){
    if(head==nullptr) return;
    cout<<head->data<<endl;
    printList_recursive(head->next);
}

void printList_reverse_recursive(Node* head){
    if(head==nullptr) return;
    printList_reverse_recursive(head->next);
    cout<<head->data<<endl;
}

Node* search(Node* head, int x){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
        if(temp->data == x){
            cout<<"Data "<<x<<" found at node "<<temp<<endl;
            return temp;
        }
    }
    cout<<x<<" is not present in the Linked List."<<endl;
    return nullptr;
}

void delete_item(Node *head, int x){
    if(head==nullptr) return;
    Node* temp = head;
    Node* prev;
    while(temp->next!=nullptr){
        prev = temp;
        temp=temp->next;
        if(temp->data == x){
            if(temp->next!=nullptr){
                prev->next = temp->next;
            }else{
                prev->next = nullptr;
            }
            delete(temp);
            cout<<"Data "<<x<<" has been deleted successfully."<<endl;
            return;
        }
    }
    cout<<"No nodes to delete."<<endl;
}


Node* reverse_iterative(Node* head){
    if(head==nullptr) return nullptr;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    while(curr!=nullptr){
        next=curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}


Node* head;
Node* reverse_recursive(Node* node){
    if(node==nullptr) return nullptr;
    if(node->next == nullptr){
        head=node;
        return head;
    }
    Node* prev = reverse_recursive(node->next);
    prev->next = node;
    node->next = nullptr;
    return node;
}

int main(){
    Node* head = getNewNode(NULL);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    printList(head);
    //printList_recursive(head);
    //printList_reverse_recursive(head);
    //Node *temp = search(head,2);
    //delete_item(head,3);
    //printList(head);
    //search(head,0);
    cout<<"REVERSE_iter"<<endl;
    Node *newHead = reverse_recursive(head);
    printList(newHead);
}