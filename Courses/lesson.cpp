#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    fstream file;
    file.open("D:\\test.txt", ios::in);

    char data[101];
    data[100] = '\0';

    string Data;
    int count = 0;

    do{
        file.read(data, 100);
        count = file.gcount();
        if(count < 100)
            data[count] = '\0';
        Data +=data;
    }while(count == 100);

    file.close();
    cout << "ALL DATA" << "\n\n";
    cout << Data << "\n\n"; 
    return 0;
}