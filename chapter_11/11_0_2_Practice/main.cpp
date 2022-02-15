//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"


int main()
{
    VECTOR::Vector testOperatorDouble(2, 2);
    double length = testOperatorDouble;
    std::cout << "Length of testOperatorDouble = " << length << std::endl;

    srand(time(0));
    double direction;
    VECTOR::Vector step;
    VECTOR::Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    
    std::cout << "Enter target distance(q to quit): ";
    while(std::cin >> target)
    {
        std::cout << "Enter step length: ";
        if(!(std::cin >> dstep))
            break;

        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, VECTOR::Vector::POL);
            result = result + step;     // x+x and y+y, it will call inline function to set magnitude and angle
            steps++;
        }

        std::cout << "After " << steps << " steps, the subject has the following location: " << std::endl;
        std::cout << result;
        result.polar_mode();
        std::cout << "or" << std::endl << result;
        std::cout << "Average outward distance per step = " 
                  << result.magval() / steps << std::endl;
        steps = 0;
        result.reset(0.0, 0.0);
        std::cout << "Enter target distance(q to quit): ";
    }

    std::cout << "Bye!" << std::endl;
    std::cin.clear();

    while (std::cin.get() != '\n')
        continue;

    return 0;
}



