//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stacktp.h"

const int Num = 10;

int main()
{
    std::srand(std::time(0));
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;

    Stack<const char *> st(stacksize);

    // In basket
    const char * in[Num] = {
            "1: Hank Gilgamesh", "2: Kiki Ishtar",
            "3: Betty Rocker", "4: Ian Flagranti",
            "5: Wolfgang Kibble", "6: Portia Koop",
            "7: Joy Almondo", "8: Xaverie Paprika",
            "9: Juan Moore", "10: Misha Mache"
    };

    // Out Basket
    const char * out[Num];
    int processed = 0;
    int nextin = 0;

    while (processed < Num)
    {
        if(st.isempty())
        {
            std::cout << "One" << std::endl;
            st.push(in[nextin + 1]);
        }
        else if(st.isfull())
        {
            std::cout << "Two" << std::endl;
            st.pop(out[processed++]);
        }
        else if(std::rand() % 2 && nextin < Num)
        {
            std::cout << "Three" << std::endl;
            st.push(in[nextin++]);
        }
        else
        {
            std::cout << "Four" << std::endl;
            st.pop(out[processed++]); 
        }
    }

    for(int i = 0; i < Num; i++)
        std::cout << out[i] << std::endl;
    
    std::cout << "Bye" << std::endl;
    return 0;
}




