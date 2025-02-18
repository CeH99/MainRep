#include <iostream>

using namespace std;

int main(void)
{
    int month;
do{
    cout << "Enter month: " << endl;
    cin >> month;

    if(1 > month || month > 12)
    cout << "Wrong month!" << endl; 

}while(1 > month || month > 12);

    if (month < 3 || month == 12)
        std::cout << "Winter";
    else if (month >= 3 && month < 6)
        std::cout << "Spring";
    else if (month >= 6 && month < 9)
        std::cout << "Summer";
    else if (month >= 9 && month < 12)
        std::cout << "Autumm";
    return 0;
}