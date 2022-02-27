//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool boot(const std::string & s);

int main()
{
    std::string input;
    std::cout << "Enter a word(q to quit): ";

    while (std::getline(std::cin, input) && input != "q")
    {
        if(boot(input))
            std::cout << input << " is palindrome!" << std::endl;
        else
            std::cout << input << " is not palindrome!" << std::endl;
        
        std::cout << "Enter another word(q to quit)";
    }
    
    std::cout << "Bye!" << std::endl;
    return 0;
}


bool boot(const std::string & s)
{
    std::string ss;
    for(char c : s)
    {
        if(isalpha(c))
            ss += c;
    }
    transform(ss.begin(), ss.end(), ss.begin(), tolower);

    std::cout << "ss = " << ss << std::endl;
    std::string rev(ss.rbegin(), ss.rend());
    return (rev == ss);
}

