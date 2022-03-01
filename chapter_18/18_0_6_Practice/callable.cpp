//Copyright (c) 2022 user1687569
#include <iostream>
#include "somedef.h"

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }


int main()
{
    double y = 1.21;
    std::cout << "Function pointer dub: " << std::endl;
    std::cout << "  " << use_f(y, dub) << std::endl;
    
    std::cout << "Function pointer square: " << std::endl;
    std::cout << "  " << use_f(y, square) << std::endl;

    std::cout << "Function object Fp: " << std::endl;
    std::cout << "  " << use_f(y, Fp(5.0)) << std::endl;

    std::cout << "Function object Fq: " << std::endl;
    std::cout << "  " << use_f(y, Fq(5.0)) << std::endl;

    std::cout << "Lambda expression 1: " << std::endl;
    std::cout << "  " << use_f(y, [](double u) { return u * u; }) << std::endl;

    std::cout << "Lambda expression 2: " << std::endl;
    std::cout << "  " << use_f(y, [](double u) { return u + u / 2.0; }) << std::endl;

    return 0;
}

