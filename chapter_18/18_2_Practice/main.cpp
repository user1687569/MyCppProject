//Copyright (c) 2022 user1687569
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include "cpmv.h"


int main()
{
    Cpmv one;
    std::cout << "Display one: " << std::endl;
    one.Display();

    Cpmv two("Good", "morning");
    std::cout << "Display two: " << std::endl;
    two.Display();

    Cpmv three(one);
    std::cout << "Display three: " << std::endl;
    three.Display();

    Cpmv four(one + two);
    std::cout << "Display four: " << std::endl;
    four.Display();

    Cpmv five;
    five = four;
    std::cout << "Display five: " << std::endl;
    five.Display();

    Cpmv six = one + two;
    std::cout << "Display six: " << std::endl;
    six.Display();

    return 0;
}


