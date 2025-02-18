#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

void sleep(int seconds)
{
    this_thread::sleep_for(chrono::seconds(seconds));
}

void sleep(string str)
{
    this_thread::sleep_for(chrono::seconds(stoi(str)));
}

int main()
{
    cout << "Sleeping for 10 seconds..." << endl;
    sleep(10);
    cout << "And now with the string one..." << endl;
    sleep("10");
    return 0;
}