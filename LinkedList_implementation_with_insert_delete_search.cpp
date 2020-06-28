#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int studentID;
        int studentMarks;
        Node *nextPtr;
};

Node* getNewNode(){
    Node* node = new Node;
    node->nextPtr = nullptr;
    return node;
}

typedef Node* studentCollection;


//New nodes getting added at the end

// void addStudent(Node *&head, int id, int marks){
//     while(head->nextPtr!=nullptr){
//         head = head->nextPtr;
//     }
//     Node *curr = getNewNode();
//     curr->studentID = id;
//     curr->studentMarks = marks;
//     head->nextPtr = curr;
// }


void addStudent(Node *&head, int id, int marks){
    Node *curr = getNewNode();
    curr->studentID = id;
    curr->studentMarks = marks;
    if(head == nullptr) 
        head == curr;
    else
        curr->nextPtr = head->nextPtr;
        head->nextPtr = curr;
}

double getAverageMarks(Node *&head){
    double total = 0;
    int studentCount = 0;
    if(head->nextPtr == nullptr) return 0;
    Node *curr = head;
    while(curr->nextPtr!= nullptr){
        curr=curr->nextPtr;
        total+=curr->studentMarks;
        studentCount++;
    }
    return total/studentCount;
}

bool search(Node *&head, int id){
    if(head == nullptr) return false;
    Node *curr = head;
    while(curr != nullptr){
        if(curr->studentID == id) return true;
        curr = curr->nextPtr;
    }
    return false;
}

bool remove(Node *&head, int id){
    if(head == nullptr) return false;
    Node *curr = head;
    Node *prev = head;
    while(curr!=nullptr){
        prev = curr;
        curr=curr->nextPtr;
        if(curr->studentID == id){
            prev->nextPtr = curr->nextPtr;
            delete(curr);
            curr = NULL;
            return true;
        }
    }
    return false;
}

int main(){
    studentCollection sc;
    Node* head = getNewNode();
    sc=head;
    addStudent(sc, 1001, 78);
    addStudent(sc, 1002, 83);
    addStudent(sc, 1003, 91);
    addStudent(sc, 1004, 94);
    addStudent(sc, 1005, 93);

    // do{
    //     sc = sc->nextPtr;
    //     cout<<sc->studentID<<" ";
    //     cout<<sc->studentMarks<<endl;
    // }while(sc != nullptr);
    sc = head;
    while(sc->nextPtr!=nullptr){
        sc = sc->nextPtr;
        cout<<sc->studentID<<" ";
        cout<<sc->studentMarks<<endl;
    }

    sc = head;
    double avg = getAverageMarks(sc);
    cout<<"Average marks: "<<avg<<endl;

    sc = head;
    bool isPresent = search(head,1006);
    cout<<"Is present: "<<isPresent<<endl;

    sc = head;
    bool isRemoved = remove(head, 1005);
    cout<<"Is removed: "<<isRemoved<<endl;

    sc = head;
    while(sc->nextPtr!=nullptr){
        sc = sc->nextPtr;
        cout<<sc->studentID<<" ";
        cout<<sc->studentMarks<<endl;
    }
}