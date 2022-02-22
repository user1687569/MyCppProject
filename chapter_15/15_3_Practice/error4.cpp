//Copyright (c) 2022 user1687569
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "exc_mean.h"

// 将对象用作异常类型

double hmean(double a, double b);
double gmean(double a, double b);


int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try{                    
            z = hmean(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y
                      << " is " << z << std::endl;
            std::cout << "Geometric mean of " << x << " and " << y
                      << " is " << gmean(x, y) << std::endl;
            std::cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (bad_hmean & bh)    
        {
            bh.mesg();
            std::cout << bh.what();
            std::cout << "Try again." << std::endl;
            continue;
        }
        catch (bad_gmean & bg)
        {
            bg.mesg();
            std::cout << bg.what();
            std::cout << "Values used: " << bg.v1 << ", "
                      << bg.v2 << std::endl;
            std::cout << "Sorry, you don't get to play any more." << std::endl;
            break;
        }
        catch (bad_base & bb)
        {
            bb.mesg();
            std::cout << bb.what();
            break;
        }
    }

    std::cout << "Bye!" << std::endl;    
    return 0;
}


double hmean(double a, double b)
{
    if(a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}


double gmean(double a, double b)
{
    if(a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}



