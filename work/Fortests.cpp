#include <iostream>
#include <conio.h>   // для _kbhit()
#include <windows.h> // для  Sleep()
 
struct Time {
	int min;
	int sec;
};
 
int main() {
	SYSTEMTIME st;
	Time time;
	std::cout << "Enter the time (min sec): ";
	std::cin >> time.min;
	std::cin >> time.sec;
	int i = 0;
	for (int i = 0; i <= time.min * 60 + time.sec && !_kbhit(); i++) {
		GetSystemTime(&st);
		std::cout << st.wHour << ':' << st.wMinute << ':' << st.wSecond << '\n';
		Sleep(1000);
	}
}