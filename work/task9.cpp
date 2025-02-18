#include <iostream>
#include <string>
#include <map>
#include <windows.h>

std::map<char, std::string> alphabet{
    {'a', "._"},   {'b', "_..."}, {'c', "_._."}, {'d', "_.."},
    {'e', "."},    {'f', ".._."}, {'g', "__."},  {'h', "...."},
    {'i', ".."},   {'j', ".___"}, {'k', "_._"},  {'l', "._.."},
    {'m', "__"},   {'n', "_."},   {'o', "___"},  {'p', ".__."},
    {'q', "__._"}, {'r', "._."},  {'s', "..."},  {'t', "_"},
    {'u', ".._"},  {'v', "..._"}, {'w', ".__"},  {'x', "_.._"},
    {'y', "_.__"}, {'z', "__.."}, {' ', "   "}
};

std::string Func(const std::string& input)
{
    std::string output;
    for (char c : input) 
        if (alphabet.find(c) != alphabet.end()) 
            output += alphabet[c];

    return output;
}

void playSound(std::string str)
{
    for(int i = 0; i < size(str); i++)
    {
        if(str[i] == '.')
            Beep(600, 200);
        else if(str[i] == '_')
            Beep(600, 750);
        else
            Beep(600, 1000);
    }
}

int main(void)
{
    std::string input;
    std::cout << "Enter your string: " << "\n";
    std::getline(std::cin, input);
    std::cout << "----------------------------------- " << "\n";
    std::cout << "Your string in morze alphabet: " << "\n";
    std::cout << Func(input);
    playSound(Func(input));
    return 0;
}