#include <bits/stdc++.h>
using namespace std;

class Istring
{
public:
    Istring(const char* cstr=0);
    Istring(const Istring& str);
    Istring& operator=(const Istring& str);
    ~Istring();
    char* get_c_str() const { return m_data;};
    
private:
    char* m_data;
};

inline 
Istring::Istring(const char* cstr)
{
    if (cstr) {
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data, cstr);
    }
    else {
        m_data=new char[1];
        *m_data='\0';
    }
}

inline
Istring::Istring(const Istring& str)
{
    m_data=new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
}

inline
Istring& Istring::operator=(const Istring& str)
{
    if (this==&str)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data, str.m_data);
    return *this;
}

ostream& operator<<(ostream& os, const Istring& str)
{
    os << str.get_c_str();
    return os;
}

inline
Istring::~Istring()
{
    delete[] m_data;
}

int main()
{
    Istring s1();
    Istring s2("hello");

    Istring* p= new Istring("hello");
    delete p;
    cout << s2 << endl;
}