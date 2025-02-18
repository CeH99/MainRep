#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    double price;
    cout << "Enter price for 1 kg: ";
    cin >> price;
    cout << "Weight\t\tPrice" << endl;
    cout << "g     \t\t$" << endl;
    float coef = 0.1;
    int weight = 100;
    cout.precision(5);
    for(int i = 0; i < 10; i++, weight +=100, coef += 0.1)
    {
        cout << weight << "\t\t" << fixed << setprecision(2) << price*coef << endl;
    }  
    return 0;
}