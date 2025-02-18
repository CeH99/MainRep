#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Test
{
public:
std::string name;
float weight;
double dateofExpired;
float price;

Test() {};
Test(int i) {};
Test(std::fstream& file);
void Write(std::fstream& file);
void Ask();
void Print();
};

int main()
{
    int number;
    std::cout << "Enter number of fruits: " << "\n";
    std::cin >> number;

    std::vector<Test> tests;
    tests.reserve(number);

    for (int i = 0; i < number; i++) {
        tests.emplace_back(i);
    tests[i].Ask();
    }
    
//=======WRITING=======
std::fstream file;
file.open("D:/test.bin", std::ios::binary | std::ios::out);

if (!file.is_open())
{
std::cout << "OpenError!\n";
}
for (int i = 0; i < number; i++) {
    tests[i].Write(file);
}
file.close();

//=======READING=======
file.open("D:/test.bin", std::ios::binary | std::ios::in);

if (!file.is_open())
{
std::cout << "OpenError!\n";
}

std::vector<Test> readTests;

    while (file.peek() != EOF) {
            readTests.push_back(file);
        }
        for (int i = 0; i < number; i++) {
            readTests[i].Print();
        }

return 0;
}

void Test::Write(std::fstream& file)
{
file.write((char*)&name, sizeof(name));
file.write((char*)&weight, sizeof(weight));
file.write((char*)&dateofExpired, sizeof(dateofExpired));
file.write((char*)&price, sizeof(price));
}

Test::Test(std::fstream& file)
{
file.read((char*)&name, sizeof(name));
file.read((char*)&weight, sizeof(weight));
file.read((char*)&dateofExpired, sizeof(dateofExpired));
file.read((char*)&price, sizeof(price));
}

void Test::Print()
{
std::cout << "\n";
std::cout << "name: " << name << "\n";
std::cout << "weight: " << weight << "\n";
std::cout << "dateofExpired: " << dateofExpired << "\n";
std::cout << "price: " << price << "\n"; 
std::cout << "\n\n";
}

void Test::Ask(){
        std::cout << "Enter name of fruit: " << "\n";
        std::cin >> name;
        std::cout << "Enter weight of fruit: " << "\n";
        std::cin >> weight;
        std::cout << "Enter dateofExpired of fruit: " << "\n";
        std::cin >> dateofExpired;
        std::cout << "Enter price of fruit: " << "\n";
        std::cin >> price;
}