#include <iostream>
using namespace std;
class CMyString
{
private:
    int size;
    char *String;

public:
    CMyString(string a)
    {
        size = a.size();
        String = new char[size + 1];
    }

    CMyString()
    {
        size = 50;
        String = new char[size];
    }

};

int main()
{
    CMyString a("ABCDEF");
    CMyString b("1234567");
  
}
