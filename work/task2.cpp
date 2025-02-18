#include <iostream>

using namespace std;

int Func(int arr[], int size)
{
    int temp = 1000000000;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < 0 )
            return -1;
        
        if(arr[i] < temp) 
            temp = arr[i];
        else   
            continue;
    }
    return temp;
}
int main()
{
    int result;
    do {
        int size;
        cout << "Enter number of elements in arr: ";
        cin >> size;

        if (size <= 0) {
            cout << "Invalid size. Please enter a positive number." << endl;
            continue;
        }

        int arr[size];

        cout << "Enter elements in arr: " << endl;
        for (int i = 0; i < size; i++) {
            cout << "Element number #" << i + 1 << ": ";
            cin >> arr[i];
        }

        result = Func(arr, size);

        if (result == -1)
            cout << "There is a negative number in the array." << endl;
        else
            cout << "The minimal number is " << result << endl;
    }while(result == -1);
}