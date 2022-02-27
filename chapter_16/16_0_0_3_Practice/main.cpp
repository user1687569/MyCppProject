//Copyright (c) 2022 user1687569
#include <iostream>
#include <cctype>
#include <string>

void toLower(std::string & str);

int main()
{
    std::string one("Hello, I am Blockchain Lee!");
    std::cout << one << std::endl;

    toLower(one);
    std::cout << one << std::endl;

    return 0;
}


void toLower(std::string & str)
{
    for(int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
}


