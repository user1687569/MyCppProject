//Copyright (c) 2022 user1687569
#include <iostream>
#include "stringbad.h"

void callme1(StringBad &);

// 按值传递对象将调用复制构造函数，因此应该按引用传递对象
void callme2(StringBad);


int main()
{
    using std::endl;
    {
        std::cout << "Starting an inner block." << std::endl;
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");

        std::cout << "headline1: " << headline1 << std::endl;
        std::cout << "headline2: " << headline2 << std::endl;
        std::cout << "sports: " << sports << std::endl;

        callme1(headline1);
        std::cout << "headline1: " << headline1 << std::endl;
        callme2(headline2);
        std::cout << "headline2: " << headline2 << std::endl;

        std::cout << "Initialize one object to another: " << std::endl;
        StringBad sailor = sports;
        std::cout << "sailor: " << sailor << std::endl;
        
        std::cout << "Assign one object to another: " << std::endl;
        StringBad knot;
        knot = headline1;
        std::cout << "knot: " << knot << std::endl;
        std::cout << "Exiting the block." << std::endl;
    }

    std::cout << "End of main()" << std::endl;
    return 0;
}


void callme1(StringBad & strBad)
{
    std::cout << "String passed by reference: " << std::endl;
    std::cout << "\"" << strBad << "\"" << std::endl;
}


void callme2(StringBad strBad)
{
    std::cout << "String passed by value: " << std::endl;
    std::cout << "\"" << strBad << "\"" << std::endl;
}



