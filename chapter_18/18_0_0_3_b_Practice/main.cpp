//Copyright (c) 2022 user1687569
#include <iostream>

double up(double x) { return 2.0 * x; }
void r1(double &rx) { std::cout << "double & rx\n"; } 
void r1(double &&rx) { std::cout << "double && rx\n"; } 


int main()
{
    double w = 10.0;
    r1(w);
    r1(w+1);
    r1(up(w));

    return 0;
}


