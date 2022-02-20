//Copyright (c) 2022 user1687569
#include <iostream>
#include "manyfriend.h"


int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);

    std::cout << "hfi1, hfi2: ";
    show2(hfi1, hfi2);

    std::cout << "hfdb, hfi2: ";
    show2(hfdb, hfi2);

    return 0;
}


