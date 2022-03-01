//Copyright (c) 2022 user1687569
#include <iostream>

double up(double x) { return 2.0 * x; }
void r1(const double &rx) { std::cout << rx << std::endl; } 
void r2(double &rx) { std::cout << rx << std::endl; } 
void r3(double &&rx) { std::cout << rx << std::endl; } 


int main()
{
    double w = 10.0;
    r1(w);
    r1(w+1);
    r1(up(w));

    r2(w);
    // r2(w+1);        // 不合法，w+1是右值
    // r2(up(w));      // 不合法，up(w)是右值

    // r3(w);          // 不合法，w是左值
    r3(w+1);
    r3(up(w));

    return 0;
}


