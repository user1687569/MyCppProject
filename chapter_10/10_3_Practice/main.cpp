//Copyright (c) 2022 user1687569
#include <iostream>
#include "golf.h"


int main()
{
    Golf ann("Ann Bridfree", 24);
    ann.showgolf();

    Golf andy;
    int result = 0;
    andy.setGolf(result);
    if(result == 0) 
        std::cout << "Haven't set golf name!" << std::endl;
    andy.showgolf();

    int hc;
    std::cout << "Reset handicap to new value: ";
    std::cin >> hc;
    andy.setHandicap(hc);
    andy.showgolf();

    return 0;
}




