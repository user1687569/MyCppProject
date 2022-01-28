//Copyright (c) 2022 user1687569
#include <iostream>

double add(double x, double y);
double substract(double x, double y);
double calculate(double x, double y, double (*p)(double, double));

int main()
{
    double x, y;

    while(1)
    {
        std::cout << "Please enter two number: ";
        std::cin >> x >> y;
        if(!std::cin)
        {
            std::cout << "Bad input, terminate!" << std::endl;
            break;
        }
        std::cout << "Add one by another: " << calculate(x, y, add) << std::endl;
        std::cout << "Substract one by another: " << calculate(x, y, substract) << std::endl;
    }

    return 0;
}


double calculate(double x, double y, double (*p)(double, double))
{
    return (*p)(x, y);
}


double add(double x, double y)
{
    return x + y;
}


double substract(double x, double y)
{
    return x - y;
}


