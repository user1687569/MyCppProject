//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include <string>

void StringToUpper(std::string &str);

int main()
{
    int n = 0;
    int inputFlag = 0;
    std::string inputString;
    std::string inputWord;
    std::size_t position;

    std::cout << "Enter a string (q to stop): ";
    std::getline(std::cin, inputString);

    while(1)
    {        
        if(inputString == "q")
        {
            break;
        }
        StringToUpper(inputString);
        std::cout << inputString << std::endl;

        std::cout << "Next string (q to stop): ";
        std::getline(std::cin, inputString);
    }

    std::cout << "Bye." << std::endl;
    return 0;
}

void StringToUpper(std::string &str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(islower(str.at(i)))
            str.at(i) = toupper(str.at(i));
    }
}


