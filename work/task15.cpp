#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

int main(void)
{
    int time;
    cout << "Enter time(seconds): " << endl;
    cin >> time;

    this_thread::sleep_for(chrono::seconds(time));
    Beep(100, 500);

    return 0;
}