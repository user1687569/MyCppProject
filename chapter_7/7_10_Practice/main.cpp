//Copyright (c) 2022 user1687569
#include <iostream>

double add(double x, double y);
double substract(double x, double y);
double multiply(double x, double y);
double calculate(double x, double y, double (*p)(double, double));

int main()
{
    double x, y;
    double (*pf[3])(double, double) = {add, substract, multiply};

    while(1)
    {
        std::cout << "Please enter two number: ";
        std::cin >> x >> y;
        if(!std::cin)
        {
            std::cout << "Bad input, terminate!" << std::endl;
            break;
        }
        for(int i = 0; i < 3; i++)
        {
            std::cout << calculate(x, y, pf[i]) << std::endl;
        }
    }

    return 0;
}


double calculate(double x, double y, double (*p)(double, double))
{
    return (*p)(x, y);
}


double add(double x, double y)
{   
    std::cout << "Add one by another: ";
    return x + y;
}


double substract(double x, double y)
{
    std::cout << "Substract one by another: ";
    return x - y;
}


double multiply(double x, double y)
{
    std::cout << "Multuply one by another: ";
    return x * y;
}


