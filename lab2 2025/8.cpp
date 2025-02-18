#include <iostream>
#include <cmath>

using namespace std;

int myroot(int a)
{
    return sqrt(a);
}

long int myroot(long int a)
{
    return sqrt(a);
}

double myroot(double a)
{
    return sqrt(a);
}

int main()
{
    cout << myroot(49) << endl;
    cout << myroot(10201L) << endl;
    cout << myroot(5.78) << endl;

    return 0;
}