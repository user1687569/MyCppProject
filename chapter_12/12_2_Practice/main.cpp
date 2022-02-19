//Copyright (c) 2022 user1687569
#include <iostream>
#include "string.h"


int main()
{   
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    
    std::cout << s2;
    std::cin >> s3;

    s2 = "My name is " + s3;
    std::cout << s2 << ".\n";

    s2 = s2 + s1;
    s2.Stringupper();
    std::cout << "The string \n" << s2 << "\ncontains " << s2.has('A')
              << " 'A' characters in it.\n";
    
    s1 = "red";
    String rgb[3] = { String(s1), String("green"), String("blue")};
    std::cout << "Enter the name of a primary color for mixing light: ";
    
    String ans;
    bool success = false;
    while (std::cin >> ans)
    {
        ans.Stringlow();
        for(int i = 0; i < 3; i++)
        {
            if(ans == rgb[i])
            {
                std::cout << "That's right!" << std::endl;
                success = true;
                break;
            }
        }
        if(success)
            break;
        else
            std::cout << "Try again!" << std::endl;
    }

    std::cout << "Bye" << std::endl;
    return 0;
}



