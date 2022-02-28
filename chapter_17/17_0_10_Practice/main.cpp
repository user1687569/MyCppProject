//Copyright (c) 2022 user1687569
#include <iostream>
#include <exception>

const int Limit = 255;

// Enter a string for getline() processing: 
// Please pass
// me a #3 melon!
// Here is your input: 
// Please pass
// me a
// Done with phase 1
// The next input character is 3
// Enter a string for get() processing:
// I still 
// want my #3 melon!
// Here is your input: 
// I still
// want my
// Done with phase 2
// The next input character is #

int main()
{
    char input[Limit];

    std::cout << "Enter a string for getline() processing: " << std::endl;
    std::cin.getline(input, Limit, '#');
    std::cout << "Here is your input: " << std::endl;
    std::cout << input << "\nDone with phase 1\n";

    char ch;
    std::cin.get(ch);
    std::cout << "The next input character is " << ch << std::endl;

    if(ch != '\n')
        std::cin.ignore(Limit, '\n');
    
    std::cout << "Enter a string for get() processing: " << std::endl;
    std::cin.get(input, Limit, '#');
    std::cout << "Here is your input: " << std::endl;
    std::cout << input << "\nDone with phase 2\n";

    std::cin.get(ch);
    std::cout << "The next input character is " << ch << std::endl;

    return 0;
}


