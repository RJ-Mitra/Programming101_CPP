using namespace std;

class Student{
    public:
        int studentId;
        string studentName;
        int marks;

        Student(int studentId, string studentName, int marks){
            this->studentId = studentId;
            this->studentName = studentName;
            this->marks = marks;

        }

        void printDetails(){
            cout<<"Details:"<<endl;
            cout<<" Student ID: "+studentId<<endl;
            cout<<"Student Name: "+studentName<<endl;
            cout<<" Student Marks: "+marks<<endl;
            // cout<<"\n Student ID: " + to_string(studentId) + "\n";
            // cout<<"\n Student Name: "+ studentName + "\n";
            // cout<<"\n Student Marks: "+ to_string(marks) + "\n";
        }

};