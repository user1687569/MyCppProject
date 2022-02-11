//Copyright (c) 2022 user1687569
#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    Sales bitcoin;
    const double ar[] = {1.2, 2.3, 3.4, 4.5};
    
    setSales(bitcoin, ar, 4);
    showSales(bitcoin);

    Sales ethereum;
    setSales(ethereum);
    showSales(ethereum);

    return 0;
}


