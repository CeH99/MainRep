#include <iostream>
#include <string>

using namespace std;

int Func(int* hours, int* money_per_hour, int size)
{
    int result = 0; 
    for(int i = 0; i < size; i++)
    {
        result += hours[i]*money_per_hour[i];
    }
    return result;
}

int main()
{
    std::string workers[] = {"Andy", "Billy", "Daive"}; 
    int hours[3] = {0};
    int money_per_hour[3] = {0};

    for(int i = 0; i < size(workers); i++)
    {
        cout << "Enter hours of work for worker " << workers[i] << ": ";
        cin >> hours[i];
        cout << "Enter money per hour for worker " << workers[i] << ": ";
        cin >> money_per_hour[i];
    }
    cout << "Overall sum of salaries: " << Func(hours, money_per_hour, size(workers)) << endl;


    return 0;
}