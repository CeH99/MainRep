#include <iostream>

void Func(double* arr, int size)
{
    double tmp = arr[0];
    double tmp2 = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(tmp < arr[i])
            tmp = arr[i];
            
        if(tmp2 > arr[i])
            tmp2 = arr[i];
    }

    std::cout << "max = " << tmp << "    " << "min = " << tmp2 << "\n";
}

int main()
{
    int number;
    double result;
    std::cout << "Enter number of drobey: ";
    std::cin >> number;
    
    double array[number];
    
    for(int i = 0; i < number; i++)
    {
        std::cout << "Enter number #" << i+1 << " :" << "\n";
        std::cin >> array[i];
    }

    for(int i = 0; i < number; ++i)
    {
        result += array[i];
    }
    result /= number;

    std::cout << "avg number is: " << result << "\n";
    Func(array, number);
    
    return 0;
}