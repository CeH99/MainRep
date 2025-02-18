#include <iostream>

using namespace std;

bool isIcecreamsandwich(string str)
{
    string leftbread;
    string center;
    string rightbread;

    leftbread += str[0];

    for(int i = 1; i < size(str); i++)
    {
        if(str[i] == str[i-1])
        {
            leftbread += str[i];
        }
        else
        break;
    }

    for(int i = (size(leftbread) + 1); i < size(str); i++)
    {
        if(str[i] == str[i-1])
        {
            center += str[i];
        }
        else
        break;
    }

    center = center + str[size(leftbread)];

    for(int i = (size(leftbread) + size(center)); i < size(str); i++)
    {
            rightbread += str[i];
    }

    if(leftbread == rightbread)
        return true;
    else
        return false;

}

int main(void)
{
    if(isIcecreamsandwich("AAAoooAAA"))
    cout << "this is a sandwich"<< endl;
    else
    cout << "this is not a sandwich" << endl;

    if(isIcecreamsandwich("AAAoooAA"))
    cout << "this is a sandwich"<< endl;
    else
    cout << "this is not a sandwich" << endl;

    if(isIcecreamsandwich("AA"))
    cout << "this is a sandwich"<< endl;
    else
    cout << "this is not a sandwich" << endl;
    return 0;
}