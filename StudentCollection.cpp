//Student records class

#include<bits/stdc++.h>
using namespace std;

class StudentRecords{
    public:
        StudentRecords(){
            this->_id = "0000";
            this->_marks = -1;
            this->_name = "";
        }
        
        StudentRecords(string id, string name, int marks){
            setId(id);
            setName(name);
            setMarks(marks);
        }
        

        string id(){
            return _id;
        }

        void setId(string newId){
            if(newId.size() == 4){
                this->_id = newId;
            }
        }

        string name(){
            return _name;
        }

        void setName(string newName){
            if(newName.size()>0){
                this->_name = newName;
            }
        }

        int marks(){
            return _marks;
        }

        void setMarks(int newMarks){
            if(isValidMarks(newMarks)){
                this->_marks = newMarks;
            }
        }

    private:
        string _id;
        string _name;
        int _marks;

    public:
        bool isValidMarks(int marks){
            if(marks>=0 && marks<=100) return true;
            return false;
        }

        string grade(){
            if(!isValidMarks(this->_marks)) return "Invalid Marks";
            const int NUMBER_CATEGORIES = 11;
            const string LETTER_GRADES[] = {"F","D","D+","C-","C","C+","B-","B","B+","A-","A"};
            const int LOWEST_GRADE_SCORES[] = {0,60,67,70,73,77,80,83,87,90,93};
            int category = 0;
            while(category<NUMBER_CATEGORIES && LOWEST_GRADE_SCORES[category] < this->_marks){
                ++category;
            }
            return LETTER_GRADES[category-1];
        }
};


class StudentCollection{
    private:
        struct StudentNode{
            StudentRecords studentData;
            StudentNode* next;
        };

    public:
        StudentCollection(){
            _listHead = nullptr;
        }

        ~StudentCollection(){
            cout<<"Destructor called."<<endl;
            deleteList(_listHead);
            cout<<"Object has been deleted."<<endl;
        }
        
        //Copy constructor
        StudentCollection(const StudentCollection &original){
            _listHead = copiedList(original._listHead);
        }

        //Override the '=' operator for deep copy of student collection (linked list)
        StudentCollection& operator=(const StudentCollection &rhs){
            if(this != &rhs){
                delete(_listHead);
                _listHead = copiedList(rhs._listHead);
            }
            return *this;
        }

        void addRecord(StudentRecords newStudent){
            StudentNode* newNode = new StudentNode;
            newNode->studentData = newStudent;
            newNode->next = _listHead; //setting path of new node to the prev head node, so that new node becomes the head
            _listHead = newNode; //setting the new node as the head node of the list
        }

        StudentRecords getRecord(string id){
            StudentNode* temp = _listHead;
            while(temp!=nullptr && temp->studentData.id()!=id){
                temp=temp->next;
            }
            if(temp==nullptr) return StudentRecords("0000","",-1);
            return temp->studentData;
        }

        void removeRecord(string id){
            StudentNode* temp = _listHead;
            StudentNode* prev = nullptr;
            while(temp!=nullptr && temp->studentData.id()!=id){
                prev = temp;
                temp=temp->next;
            }
            if(temp==nullptr) return;
            if(prev==nullptr) _listHead = _listHead->next;
            else{
                prev->next = temp->next;
            }
            delete temp;
        }

        void getAllRecords(){
            StudentNode* temp = _listHead;
            while(temp!=nullptr){
                cout<<"-----------------------"<<endl;
                cout<<"Student ID: "<<temp->studentData.id()<<endl;
                cout<<"Student Name: "<<temp->studentData.name()<<endl;
                cout<<"Student Marks: "<<temp->studentData.marks()<<endl;
                cout<<"-----------------------"<<endl;
                temp=temp->next;
            }
        }

    private:
        typedef StudentNode* studentList; //renaming StudentNode pointer type to studentList
        studentList _listHead; //declaring head node

        void deleteList(studentList &listPtr){
            while(listPtr!=nullptr){
                StudentNode* temp = listPtr->next;
                listPtr = listPtr->next;
                delete temp;
            }
        }

        //Deep copy of two lists to prevent cross-linking and accidental deletion
        //return type: studentList (or node)
        studentList copiedList(const studentList original){
            if(original==nullptr) return nullptr;
            studentList newList = new StudentNode; //create new list head node in which we will copy the original list, starting with head node
            newList->studentData = original->studentData; //We copy the data in the head of the original list to the head of new list
            StudentNode *oldListPtr = original->next; //oldList Ptr will have address of the next node in original list
            StudentNode *newListPtr = newList; //newListPtr will have location of the prev node in the new list
            while(oldListPtr!=nullptr){ //Iterates till the old list has no nodes left
                newListPtr->next = new StudentNode; //creates the next node
                newListPtr = newListPtr->next; //moves to the newly created node
                newListPtr->studentData = oldListPtr->studentData; //copies data into the newly created node
                oldListPtr=oldListPtr->next; //moves to the next node in the old list
            }
            newListPtr->next = nullptr;//Set next pointer of last node to null
            return newList;//returns head of the new copied list

        }
};

int main(){
    StudentCollection s;
    StudentRecords st3("1003","Rudra",93);
    StudentRecords st2("1002","Sam",95);
    StudentRecords st1("1001","Utsha",97);
    s.addRecord(st3);
    s.addRecord(st2);
    s.addRecord(st1);
    s.getAllRecords();
    StudentRecords res = s.getRecord("1001");
    cout<<res.name()<<endl;
    cout<<res.id()<<endl;
    cout<<res.marks()<<endl;
    StudentCollection s2 = StudentCollection(s);
    s.removeRecord("1002");
    s.getAllRecords();
    s2.getAllRecords();
}