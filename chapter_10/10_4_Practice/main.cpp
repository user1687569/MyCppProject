//Copyright (c) 2022 user1687569
#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    const double ar[] = {1.2, 2.3, 3.4, 4.5};
    
    Sales bitcoin(ar, 4);
    bitcoin.showSales();

    Sales ethereum;
    ethereum.setSales();
    ethereum.showSales();

    return 0;
}


