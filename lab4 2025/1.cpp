#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int selectRandomElement(int stream[], int size) {
    int selected = -1; // Initial value
    int count = 0; // Element counter

    for (int i = 0; i < size; i++) {
        count++;
        if (rand() % count == 0) { // Probability of selection 1/count
            selected = stream[i];
        }
    }
    return selected;
}

int main() {
    srand(time(0)); // Initialize RNG
    
    int data[] = {1, 2, 3, 4, 5}; // Input list
    int size = sizeof(data) / sizeof(data[0]);
    int frequency[5] = {0}; // To count the frequency of selected elements
    
    int trials = 100000; // Number of iterations for statistical analysis
    
    for (int i = 0; i < trials; i++) {
        int chosen = selectRandomElement(data, size);
        frequency[chosen - 1]++; // Since elements start from 1
    }
    
    // Output frequency of selected elements
    cout << "Selection frequencies:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << data[i] << " selected " << frequency[i] << " times (" 
             << (frequency[i] / (double)trials) * 100 << "%)" << endl;
    }
    
    return 0;
}