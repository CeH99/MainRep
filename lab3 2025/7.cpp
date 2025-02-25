#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dice {
private:
    int value;
public:
    Dice() { value = 1; }
    void roll() {
        value = rand() % 6 + 1;
        cout << value << " ";
    }
};

int main() {
    srand(time(0));
    
    Dice dice[4];
    
    for (int i = 0; i < 5; i++) { // 5 кидків
        cout << "Roll " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            dice[j].roll();
        }
        cout << endl;
    }
    
    return 0;
}
