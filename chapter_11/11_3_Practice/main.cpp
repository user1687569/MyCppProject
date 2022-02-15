//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "vector.h"


int main()
{
    srand(time(0));
    double direction;
    VECTOR::Vector step;
    VECTOR::Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    unsigned long maxSteps = 0;
    unsigned long minSteps = ULONG_MAX;
    unsigned long sumSteps = 0;
    double averageSteps = 0.0;
    double count = 0.0;
    
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
        minSteps = minSteps < steps ? minSteps : steps;
        maxSteps = maxSteps > steps ? maxSteps : steps;
        count += 1;
        sumSteps += steps;
        std::cout << result;
        result.polar_mode();
        std::cout << "or" << std::endl << result;
        std::cout << "Average outward distance per step = " 
                  << result.magval() / steps << std::endl;
        steps = 0;
        result.reset(0.0, 0.0);
        std::cout << "Enter target distance(q to quit): ";
    }

    averageSteps = sumSteps / count;
    std::cout << "Finally, Min steps:[" << minSteps << "], Max steps:[" << maxSteps << "], average steps:[" << averageSteps << "]" << std::endl;  

    std::cout << "Bye!" << std::endl;
    std::cin.clear();

    while (std::cin.get() != '\n')
        continue;

    return 0;
}



