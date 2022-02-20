//Copyright (c) 2022 user1687569
#include <iostream>
#include "friendTemp.h"


int main()
{
    std::cout << "No objects declared: ";
    counts();

    HasFriend<int> hfi1(10);
    std::cout << "After hfil declared: ";
    counts();

    HasFriend<int> hfi2(20);
    std::cout << "After hfil2 declared: ";
    counts();

    HasFriend<double> hfdb(10.5);
    std::cout << "After hfdb declared: ";
    counts();

    reports(hfi1);
    reports(hfi2);
    reports(hfdb);

    return 0;
}


