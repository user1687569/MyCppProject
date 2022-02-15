//Copyright (c) 2022 user1687569
#include <iostream>
#include "stoneweight.h"


int main()
{   
    int i;
    int count = 0;
    double poundValue; 
    StoneWeight array[6] = {
        StoneWeight(128.8),
        StoneWeight(10, 6.8),
        StoneWeight(9, 7.6, StoneWeight::FLOAT_POUNDS_FORM)
    };

    for(i = 3; i < 6; i++)
    {
        std::cout << "Pls enter stoneweight(Float pounds form)" << std::endl;
        std::cout << "array[" << i << "]: ";
        while(!(std::cin >> poundValue))
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input; Please enter a double value: ";
        }

        array[i] = poundValue;
    }

    StoneWeight minObject = array[0];
    StoneWeight maxObject = array[0];

    for(i = 1; i < 6; i++)
    {
        minObject = minObject < array[i] ? minObject : array[i];
        maxObject = maxObject > array[i] ? maxObject : array[i];
    }

    StoneWeight compareObject(11, 0);
    for(i = 0; i < 6; i++)
    {
        if(array[i] >= compareObject)
            count += 1;
    }
    
    minObject.float_pounds_mode();
    maxObject.float_pounds_mode();
    std::cout << "Minimal StoneWeight Object is: " << minObject;
    std::cout << "Maximum StoneWeight Object is: " << maxObject;
    std::cout << count << " objects greater than or equal to " << compareObject; 

    return 0;
}



