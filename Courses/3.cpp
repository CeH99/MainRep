#include <iostream>

using namespace std;

void Func1(float*& a, int b)
{
    if(a != nullptr)
    {
        delete a;
        a = nullptr;
    }

    a = new float[b];
    for(int i = 0; i < b; i++)
    {
        a[i] = i*2+1;
    }
}

void Func2(float* a, int b)
{
    if(a != nullptr)
    {
         for(int i = 0; i < b; i++)
        {
            cout << "element number #" << i+1 << " is " << a[i] << endl;
        }
    }
    else{
        exit;
    }
}
int main(void)
{
    float* a = nullptr;
    int size = 20;
    Func1(a, size);
    Func2(a, size);
    return 0;
}