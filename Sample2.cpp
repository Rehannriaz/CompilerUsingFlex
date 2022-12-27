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
        size = StringSize(a);
        // size = 50;
        String = new char[size];
        int i = 0;
        while (a[i] != '\0')
        {
            String[i] = a[i];
            i++;
        }
        String[i] = '\0';
    }

    CMyString(int size1)
    {
        String = new char[size1];
    }

    CMyString()
    {
        size = 50;
        String = new char[size];
    }

    CMyString operator+(CMyString b)
    {
        CMyString temp;
        int i = 0;
        while (String[i] != '\0')
        {
            temp.String[i] = this->String[i];
            i++;
        }
        int j = 0;
        while (b.String[j] != '\0')
            temp.String[i++] = b.String[j++];

        temp.String[i] = '\0';
        return temp;
    }

    void operator+=(CMyString &b)
    {
        int i = StringSize();
        int j = 0;
        while (b.String[j] != '\0')
            this->String[i++] = b.String[j++];
    }

    char &operator[](int n)
    {
        return String[n];
    }

    char operator[](int num) const
    {
        return String[num];
    }

    bool operator==(CMyString b)
    {
        int i = 0;
        while (1)
        {
            if (this->String[i] != b.String[i])
                return 0;
            if (this->String[i] == '\0')
                break;
            i++;
        }
        return 1;
    }

    bool operator!=(CMyString b)
    {
        return !(*this == b);
    }

    bool operator<(CMyString b)
    {
        int i = 0;
        while (this->String[i] != '\0' || b.String[i] != '\0')
        {
            if (String[i] == b.String[i])
            {
                i++;
                continue;
            }

            else if (String[i] < b.String[i])
                return false;
            else
                return true;
        }

        return false;
    }

    bool operator>(CMyString b)
    {
        return !(b < *this);
    }

    CMyString operator()(int num1, int num2)
    {
        CMyString c;
        int j = 0;
        for (int i = num1; i <= num2; i++, j++)
            c.String[j] = this->String[i];

        c.String[j] = '\0';
        return c;
    }

    friend ostream &operator<<(ostream &OUT, CMyString &b)
    {
        int i = 0;
        while (b.String[i] != '\0')
            OUT << b.String[i++];

        return OUT;
    }

    friend istream &operator>>(istream &input, CMyString &b)
    {
        input >> b.String;
        return input;
    }

    void operator=(CMyString b)
    {
        int i = 0;
        while (b.String[i] != 0)
        {
            String[i] = b.String[i];
            i++;
        }
        String[i] = '\0';
    }

    int StringSize()
    {
        return size;
    }
    // int StringSize()
    // {
    //     int i = 0;
    //     while (String[i] != '\0')
    //         i++;

    //     return i;
    // }
    int StringSize(string a1)
    {
        int i = 0;
        while (a1[i] != '\0')
            i++;

        return i;
    }

    CMyString operator<<(int num)
    {
        CMyString c;
        int i = 0;
        for (; i < num; i++)
            c.String[i] = String[i];

        c.String[i] = '\0';
        CMyString temp;
        int j = 0;
        while (this->String[i] != '\0')
            temp.String[j++] = String[i++];

        temp.String[j] = '\0';
        *this = temp;
        return c;
    }
    CMyString operator>>(int num)
    {
        CMyString c;
        int i = StringSize();
        int j = 0;
        int num1 = i - num;
        for (; i > num1; i--, j++)
            c.String[j] = this->String[i - 1];

        c.String[j] = '\0';

        String[num1] = '\0';
        return c;
    }

     ~CMyString()
    {
        // delete[] String;
    }
    
};

int main()
{
    CMyString a("ABCDEF");
    CMyString b("1234567");
    CMyString c;
    CMyString d;
    c=a<<2;
    cout<<c<<'\n';
    cout<<a;
}
