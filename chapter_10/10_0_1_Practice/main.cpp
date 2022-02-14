//Copyright (c) 2022 user1687569
#include <iostream>
#include "stock.h"

int main()
{
    // ###########One
    // std::cout << "Using constructors to create new objects: " << std::endl;
    // Stock stock1("NanoSmart", 12, 20.0);
    // stock1.show();

    // Stock stock2("Boffo", 2, 2.0);
    // stock2.show();

    // std::cout << "Assigning stock1 to stock2: " << std::endl;
    // stock2 = stock1;
    
    // std::cout << "Listing stock1 and stock2: " << std::endl;
    // stock1.show();
    // stock2.show();

    // std::cout << "Using a constructor to reset an object" << std::endl;
    // stock1 = Stock("Nifty Foods", 10, 50.0);
    // std::cout << "Revised stock1: " << std::endl;
    // stock1.show();
    // std::cout << "Done" << std::endl;


    // ###########Two
    const int STKS = 4;
    Stock stocks[] = {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo", 200, 2.0),
            Stock("Monolithic", 130, 3.25),
            Stock("Fleep", 60, 6.5)
    };

    std::cout << "Stock holdings: " << std::endl;
    int st;
    for(st = 0; st < STKS; st++)
        stocks[st].show();
    
    const Stock * top = &stocks[0];
    for(st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
    
    std::cout << std::endl << "Most valuable holding: " << std::endl;
    top->show();

    return 0;
}



