#include<bits/stdc++.h>
using namespace std;

class Singleton{
    private:
        int x;
        //static Singleton* instance; //static so that instance remains same for all objects
        
        Singleton(int x=0){this->x = x;} //private constructor to disallow creation of objects

    public:
        static Singleton* getInstance(){ //static so that it can be called without init
            static Singleton* instance = nullptr; //Set intial instance to null
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }

        static Singleton* getInstance(int x){ //static so that it can be called without init
            static Singleton* instance = nullptr; //Set intial instance to null
            if(instance == nullptr){
                instance = new Singleton(x);
            }
            return instance;
        }

        void setX(int x){
            this->x = x;
        }

        int getX(){
            return this->x;
        }
};

//Stack overflow answers suggest this is thread safe in g++ compilers. But in order to be totally safe,
//a mutex maybe used in the get instance method to make sure only one instance is generated even when multiple threads are present

int main(){
    Singleton *s = s->getInstance(20);
    cout<<s->getX()<<endl;
    Singleton *s2 = s2->getInstance(30);
    cout<<s<<endl;
    cout<<s->getX()<<endl;
    cout<<s2<<endl; //Both have same address
    cout<<s2->getX()<<endl;
    s2->setX(40);
    cout<<s->getX()<<endl;
}