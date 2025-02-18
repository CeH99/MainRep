#include <iostream>

using namespace std;

double Meters_to_feet(int meters)
{
    double result  = meters * 3.28084;
    return result;
}

double Meters_to_inch(int meters)
{
    double result  = meters * 39.3701;
    return result;
}

int main()
{
    int meters;
    char end = '1';
    do{
        cout << "Enter distance in meters: "; 
        cin >> meters;
        cout << "Distance in feet is " << Meters_to_feet(meters) << endl;
        cout << "Distance in inches is " << Meters_to_inch(meters) << endl;

        cout << "Enter 0 if u want to exit" << endl;
        cin >> end;
    }while(end != '0');
    return 0;
}