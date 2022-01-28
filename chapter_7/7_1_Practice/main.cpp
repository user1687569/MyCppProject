//Copyright (c) 2022 user1687569
#include <iostream>

double calculate(double x, double y);

int main()
{
    double x, y;
    double harmonicAverage;

    std::cout << "Please enter two number to calculate hormonic average: " << std::endl;
    while(std::cin >> x >> y && x != 0 && y != 0)
    {
        std::cout << "Hormonic average: " << calculate(x, y) << std::endl;
    }

    return 0;
}

double calculate(double x, double y)
{
    double hormonicAverage;
    hormonicAverage = 2.0 * x * y /(x + y);
    return hormonicAverage;
}