#include <iostream>
#include <string>

using namespace std;

void rev_str(string& a)
{
    string result;
    for(int i = a.size(); i >= 0; i-- )
    {
        result += a[i];
    }
    a = result;
}

void rev_str(string& a, string& b)
{
    string result;
    for(int i = a.size(); i >= 0; i-- )
    {
        result += a[i];
    }
    b = result;
}

int main()
{
    string a = {"Hello"};
    string b = {"Hallo"};
    string c = {"Bonjour"};
    rev_str(a);
    cout << "a: " <<  a << endl;

    rev_str(b,c);
    cout << "b: " <<  b << endl;
    cout << "c: " <<  c << endl;
    return 0;
}