//Copyright (c) 2022 user1687569
#include <iostream>
#include <functional>
#include "somedef.h"

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }


int main()
{
    double y = 1.21;
    // 调用特征标 double(double)
    std::function<double(double)> ef1 = dub;
    std::function<double(double)> ef2 = square;
    std::function<double(double)> ef3 = Fp(10.0);
    std::function<double(double)> ef4 = Fq(10.0);
    std::function<double(double)> ef5 = [](double u) { return u * u; };
    std::function<double(double)> ef6 = [](double u) { return u + u / 2.0;};

    std::cout << "Function pointer dub: " << std::endl;
    std::cout << "  " << use_f(y, ef1) << std::endl;
    
    std::cout << "Function pointer square: " << std::endl;
    std::cout << "  " << use_f(y, ef2) << std::endl;

    std::cout << "Function object Fp: " << std::endl;
    std::cout << "  " << use_f(y, ef3) << std::endl;

    std::cout << "Function object Fq: " << std::endl;
    std::cout << "  " << use_f(y, ef4) << std::endl;

    std::cout << "Lambda expression 1: " << std::endl;
    std::cout << "  " << use_f(y, ef5) << std::endl;

    std::cout << "Lambda expression 2: " << std::endl;
    std::cout << "  " << use_f(y, ef6) << std::endl;

    return 0;
}


