//Copyright (c) 2022 user1687569
#include <iostream>
#include "tv.h"


int main()
{
    Tv s42;
    std::cout << "Initial settings for 42: " << std::endl;
    s42.settings();

    s42.onoff();
    s42.chanup();
    std::cout << std::endl << "Adjusted settings for 42: " << std::endl;
    s42.settings();

    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    std::cout << std::endl << "42 settings after using remote: " << std::endl;
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    std::cout << std::endl << "58 settings: " << std::endl;
    s58.settings();

    return 0;
}




