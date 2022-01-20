//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include <string>

const std::string compareWord = "word";

int main()
{
    int n = 0;
    int inputFlag = 0;
    std::string inputString;
    std::string inputWord;
    std::size_t position;


    std::cout << "Enter words(to stop, type the word done): " << std::endl;
    std::getline(std::cin, inputString);

    while(1)
    {
        if(inputFlag == 1)
        {
            std::cout << "Enter words(to stop, type the word done): " << std::endl;
            std::getline(std::cin, inputString);
            inputFlag = 0;
        }

        position = inputString.find_first_of(' ');
        if(position == std::string::npos)
        {
            inputFlag = 1;
        }
        inputWord = inputString.substr(0, position);
        inputString = inputString.substr(position + 1);
        
        if(inputWord == "word")
        {
            break;
        }
        n++;
        std::cout << inputWord << std::endl;
    }

    std::cout << "You entered a total of " << n << " words." << std::endl;
    return 0;
}




