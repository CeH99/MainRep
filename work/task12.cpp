#include <iostream>
using namespace std;

int* Func(int* arr1, int size1, int* arr2, int size2)
{
    int* resultarr = new int[size1 + size2];
    int i = 0;

    for (; i < size1; ++i)
    {
        resultarr[i] = arr1[i];
    }

    for (int j = 0; j < size2; ++j, ++i)
    {
        resultarr[i] = arr2[j];
    }

    int tmp = resultarr[0];
    for (int i = 0; i < size1 + size2 - 1; i++)
    {
        for(int j = 0; j < size1 + size2 - i; j++)
        {
            if (resultarr[j] > resultarr[j + 1]) {
                int tmp = resultarr[j];
                resultarr[j] = resultarr[j + 1];
                resultarr[j + 1] = tmp;
            }
        }
    }
    return resultarr;
}

int main(void)
{
    int size1, size2;
    cout << "Enter size of arr1: " << endl;
    cin >> size1;
    cout << "Enter size of arr2: " << endl;
    cin >> size2;

    int arr1[size1];
    int arr2[size2];
    for(int i = 0; i < size1; ++i)
    {
        cout << "Enter element #" << i+1 << " of arr1: ";
        cin >> arr1[i];
    }

    for(int i = 0; i < size2; ++i)
    {
        cout << "Enter element #" << i+1 << " of arr2: ";
        cin >> arr2[i];
    }

    int* result = Func(arr1, size1, arr2, size2);
    cout << "New sorted arr: " << endl;
    for(int i = 0; i < size1 + size2; ++i)
    {
        cout << result[i] << " "; 
    }
    return 0;
}