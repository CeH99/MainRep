#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int secretnumber[3] = { 0 };
    int snumber;
    
    int guessnumber;
    int humannumber[3] = { 0 };
        
    snumber = rand() % (1000 - 1 + 1);
    while (1) {
        cout << "Guess the number" << endl;
        do {
            cout << "Your guess: "; 
            cin >> guessnumber;
            
            if (guessnumber > 999 || guessnumber < 1)
                cout << "Enter number between 1 and 1000!" << endl;

        } while (guessnumber > 999 || guessnumber < 1);

        if (guessnumber == snumber) {
            cout << "You guessed it! It`s " << snumber << endl;
            break;
        }

        humannumber[0] = guessnumber / 100;
        humannumber[1] = guessnumber / 10 % 10;
        humannumber[2] = guessnumber % 10;

        secretnumber[0] = snumber / 100;
        secretnumber[1] = snumber / 10 % 10;
        secretnumber[2] = snumber % 10;

        int mutchesOnRightPlace = 0;
        int mutches = 0;

        for (int i = 0; i < 3; i++)
        {
            if (secretnumber[i] == humannumber[i])
                mutchesOnRightPlace++;

            for (int j = 0; j < 3; j++)
                if (secretnumber[i] == humannumber[j]) {
                    mutches++;
                    break;
                }
        }

        cout << "Guessed on right place: " << mutchesOnRightPlace << "   " << "Mutches: " << mutches << endl;
    }

    return 0;
}

