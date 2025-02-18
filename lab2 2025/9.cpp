#include <iostream>
#include <cstdlib>

double atof(int value) {
    return value * 1.23;
}

int main() {
    const char* str = "123.45";
    double num = atof(str); 
    std::cout << "Standart atof(\"123.45\") = " << num << std::endl;

    int value = 42;
    double num2 = atof(value);
    std::cout << "Overload atof(42) = " << num2 << std::endl;

    return 0;
}

/*
У C++ не можна перевантажити функції atof, atoi і atol, оскільки вони вже оголошені 
в стандартній бібліотеці з певними сигнатурами.
Причина в тому, що перевантаження функцій у C++ можливе лише в межах одного простору імен,
 а оскільки ці функції належать до стандартної бібліотеки (std),
  ми не можемо їх перевантажити без зміни стандартної бібліотеки, що заборонено.*/
