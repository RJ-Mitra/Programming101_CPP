#include<bits/stdc++.h>
using namespace std;

class String{
    private:
        char* m_Buffer;
        unsigned int m_Size;
    public:
        String(const char* string){
            this->m_Size = strlen(string);
            this->m_Buffer = new char[m_Size+1];
            memcpy(m_Buffer,string,m_Size);
            m_Buffer[m_Size] = 0;
        }

        ~String(){
            delete[] m_Buffer;
        }

        String(const String& other)
            : m_Size(other.m_Size)
        {
            this->m_Buffer = new char[m_Size+1];
            memcpy(m_Buffer, other.m_Buffer, m_Size+1);
        }

        char& operator[](int index){
            return m_Buffer[index];
        }

    friend ostream& operator<<(ostream& stream, const String& string);
};

ostream& operator<<(ostream& stream, const String& string){
    stream<<string.m_Buffer;
    return stream;
}

int main(){
    String string = "Rudra";
    String second = string;
    second[4] = 'o';

    cout<<string<<endl;
    cout<<second<<endl;
}