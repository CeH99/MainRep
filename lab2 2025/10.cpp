#include <iostream>

using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

char min(char a, char b) {
    return (a < b) ? a : b;
}

double min(double a, double b) {
    return (a < b) ? a : b;
}

int main()
{
    cout << min(30, 10) << endl;
    cout << min('a' , 'b') << endl;
    cout << min(5.44456, 5.5) << endl;

    return 0;
}