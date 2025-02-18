#include <iostream>

using namespace std;

void Func1(int*& a)
{
    if(a != nullptr)
    {
        delete a;
        a = nullptr;
    }

    a = new int(20);

}
int main(void)
{
    int* a = new int(10);

    int* b = nullptr;
    Func1(a);
    Func1(b);
    cout << "Ptr without dynamic memory " << *a << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ptr with dynamic memory " << *b << endl;

    return 0;
}