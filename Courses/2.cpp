#include <iostream>

using namespace std;

int main(void)
{
    struct Fruit{
        string name;
        int weight;
        string data;
    };

    Fruit Banana;
    Fruit Apple;
    Fruit Orange;
    
    Fruit fruits[3];
    fruits[0] = Banana;
    fruits[1] = Apple;
    fruits[2] = Orange;


    cout << "Enter name, weight and data of expire of banana" << endl;
    cin >> fruits[0].name;
    cin >> fruits[0].weight;
    cin >> fruits[0].data;
    cout << "Banana`s parameters: " << endl;
    cout <<  fruits[0].name << endl;
    cout <<  fruits[0].weight << " gramms" << endl;
    cout <<  fruits[0].data << endl;
    return 0; 
}