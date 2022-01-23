//Copyright (c) 2022 user1687569
#include <iostream>
#include <cctype>

int main()
{
    char ch;

    while(std::cin.get(ch) && ch != '@' && isprint(ch))
    {
        if(isalpha(ch))
        {
            if(islower(ch))
                std::cout << char (toupper(ch));
            else
                std::cout << char (tolower(ch));
        }
        else if(isdigit(ch)){
            ;
        }
        else 
            std::cout << ch;
    }

    return 0;
}

