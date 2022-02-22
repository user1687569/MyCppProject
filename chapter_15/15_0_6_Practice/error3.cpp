//Copyright (c) 2022 user1687569
#include <iostream>
#include <cfloat>

// 异常机制
double hmean(double a, double b);


int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try{                    // start of try block
            z = hmean(x, y);
        }                       // end of try block
        catch (const char * s)  // exception hanlder, char * 表明该处理程序与字符串异常匹配            
        {
            std::cout << s << std::endl;
            std::cout << "Enter a new pair of numbers: ";
            continue;
        }

        std::cout << "Harmonic mean of " << x << " and " << y
                  << " is " << z << std::endl;

        std::cout << "Enter next set of numbers <q to quit>: ";
    }

    std::cout << "Bye!" << std::endl;    
    return 0;
}


double hmean(double a, double b)
{
    if(a == -b)
    {
        throw "bad hmean() arguments: a = -b not allowed";
    }

    return 2.0 * a * b / (a + b);
}


