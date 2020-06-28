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


int main(){
    StudentRecords s1 = StudentRecords("1001","Rudra",93);
    StudentRecords s2 = StudentRecords();
    s2.setName("Sam");
    s2.setId("1002");
    s2.setMarks(98);
    
    
    cout<<s1.name()<<endl;
    cout<<s2.id()<<endl;
    
    cout<<s1.marks()<<endl;
    cout<<s1.grade()<<endl;
    
    s1.setMarks(97);
    cout<<s1.marks()<<endl;
    cout<<s1.grade()<<endl;
}