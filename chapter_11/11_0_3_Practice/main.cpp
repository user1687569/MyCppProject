//Copyright (c) 2022 user1687569
#include <iostream>
#include "stoneweight.h"


int main()
{
    StoneWeight incognito = 275; // use StoneWeight(double lbs), converting int to double
    StoneWeight wolfe(285.7);
    StoneWeight taft(21, 8.8);

    std::cout << "The celebrity weighed ";
    incognito.show_stone();

    std::cout << "The detective weighed ";
    wolfe.show_stone();

    std::cout << "The President weighed ";
    taft.show_stone();

    incognito = 276.8;
    std::cout << "After dinner, the celebrity weighed ";
    incognito.show_stone();
    incognito.show_lbs();

    taft = 325;
    std::cout << "After dinner, the President weighed ";
    taft.show_lbs();

    StoneWeight pingpong(10, 8);
    double pingpongweight = pingpong;
    int nPingpongweight = pingpong;
    std::cout << "pingpong weight(double): " << pingpongweight << std::endl;
    std::cout << "pingpong weight(integer): " << nPingpongweight << std::endl;

    StoneWeight pingpong2;
    pingpong2 = pingpong * 2.0;
    std::cout << "pingpong2 weighed(double): ";
    pingpong2.show_lbs();
    std::cout << "pingpong2 weighed(integer): ";
    pingpong2.show_stone();

    StoneWeight pingpong3;
    pingpong3 = 3.0 * pingpong;
    std::cout << "pingpong3 weighed(double): ";
    pingpong3.show_lbs();
    std::cout << "pingpong3 weighed(integer): ";
    pingpong3.show_stone();

    return 0;
}



