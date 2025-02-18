#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cout << "Enter string " << "\n";
    std::cin >> str;
    int a = 0;
    for(int i = 0; i < size(str); i++)
    {
        if(str[i] == '.')
        {
            std::cout << "Its not a number without dot!" << "\n";
            a = 1;
        }
    }
    if(a != 1)
    {
        std::cout << "Its a number without dot!" << "\n";
    }
    return 0;
}