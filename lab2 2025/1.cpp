#include <iostream>
#include <iomanip> // Для управления форматированием вывода
#include <string>

using namespace std;

double Func(double* hours, double* money_per_hour, int size)
{
    double result = 0.0; 
    for(int i = 0; i < size; i++)
    {
        result += hours[i] * money_per_hour[i];
    }
    return result;
}

int main()
{
    std::string workers[] = {"Andy", "Billy", "Daive"}; 
    double hours[3] = {0};
    double money_per_hour[3] = {0};

    for(int i = 0; i < size(workers); i++)
    {
        cout << "Enter hours of work for worker " << workers[i] << ": ";
        cin >> hours[i];
        cout << "Enter money per hour for worker " << workers[i] << ": ";
        cin >> money_per_hour[i];
    }
    
    double total_salary = Func(hours, money_per_hour, size(workers));
    
    cout << fixed << setprecision(2);
    cout << "Overall sum of salaries: " << total_salary << endl;

    return 0;
}
