//Copyright (c) 2022 user1687569
#include <iostream>
#include "tmp2tmp.h"


int main()
{
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);

    report(hfi1);
    report(hfi2);
    report(hfdb);

    std::cout << "counts<int>() output:" << std::endl;
    counts<int>();
    std::cout << "counts<double>() output:" << std::endl;
    counts<double>();

    return 0;
}


