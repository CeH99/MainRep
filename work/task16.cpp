#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Func(int time)
{
    int minutes = 0;
    int seconds = 0;
    for(int i = 0; i < time; i++, seconds++)
    {
        if(seconds == 60)
        {
            minutes++;
            seconds = 0;
        }
        if(minutes < 10 && seconds > 9)
            cout << "0" << minutes << ":" << seconds << endl;
        else if(minutes < 10 && seconds < 10)
            cout << "0" << minutes << ":" << "0" << seconds << endl;
        else if(seconds < 10 && minutes > 9)
            cout << minutes << ":" << "0" << seconds << endl;
        else
            cout << minutes << ":" << seconds << endl;

        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{
    int timesec;
    cout << "Enter time(in seconds): " << endl;
    cin >> timesec;

    Func(timesec);

    return 0;
}