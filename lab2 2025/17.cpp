#include <iostream>
#include <ctime>

using namespace std;

class time_and_date {
private:
    time_t timestamp;

public:
    time_and_date() {
        timestamp = time(nullptr); // getting current time
    }

    void show_time() {
        struct tm* local_time = localtime(&timestamp); // converting to struct tm

        cout << "System time: " 
             << local_time->tm_hour << ":" 
             << local_time->tm_min << ":" 
             << local_time->tm_sec << endl;

        cout << "System date: " 
             << local_time->tm_mday << "." 
             << (local_time->tm_mon + 1) << "." // bcs first month is 0
             << (local_time->tm_year + 1900) << endl; // bcs ono hranit years from 1900(2024 its 124)
    }
};

int main() {
    time_and_date a;
    a.show_time();

    return 0;
}
