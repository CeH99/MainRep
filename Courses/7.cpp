#include <iostream>
#include <vector>
#include <string> 
#include <set>

using namespace std;

void PrintVector(vector<string>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "Element number #" << i + 1 << ": " << vec[i] << endl;
    }
}

void PrintVector2(vector<string>& vec)
{
    int i = 0;
    for (vector<string>::iterator it = vec.begin(); it < vec.end(); it++, i++)
    {
        cout << "Element number #" << i + 1 << ": " << *it << endl;
    }
}
int main()
{   
    vector<string> vec = {"First", "Second", "Third", "additional elem"};

    PrintVector(vec);
    cout << "_____________________________________" << endl;
    PrintVector2(vec);
    return 0;
}
