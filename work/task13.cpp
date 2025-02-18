#include <iostream>

int main()
{
    int minutes;
    std::cout << "Minutes: " << "\n";
    std::cin >> minutes;
    int hours = 0;
    while(minutes > 0)
    {
        minutes -= 60;
        hours++;
    }

    std::cout << "It`s " << hours-1 << " hours " << "and " << minutes*(-1) << " minutes " << "\n";
    return 0;
}