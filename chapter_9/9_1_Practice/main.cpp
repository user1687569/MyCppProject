//Copyright (c) 2022 user1687569
#include <iostream>
#include "golf.h"

int main()
{
    golf ann;
    setgolf(ann, "Ann Bridfree", 24);
    showgolf(ann);

    golf andy;
    int result = 0;
    result = setgolf(andy);
    if(result == 0)
        std::cout << "Haven't set golf name!" << std::endl;
    showgolf(andy);

    int hc;
    std::cout << "Reset handicap to new value: ";
    std::cin >> hc;
    handicap(andy, hc);
    showgolf(andy);

    return 0;
}



