//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    int n;
    int sum = 0;
    int minValue, maxValue;
    std::cout << "Enter first integer: ";
    std::cin >> minValue;
    std::cout << "Enter another integer: ";
    std::cin >> maxValue;
    
    if(minValue > maxValue)
    {
        minValue = minValue ^ maxValue;
        maxValue = maxValue ^ minValue;
        minValue = maxValue ^ minValue;
    }

    for(n = minValue; n <= maxValue; n++)
    {
        sum += n;
    }

    std::cout << "The sum of integer list is: " << sum << std::endl;
    return 0;
}

//a = a ^ b;
//b = b ^ a;  b = b ^ (a ^ b) = b ^ a ^ b = b ^ b ^ a = (b ^ b) ^ a = a;
//a = b ^ a;  a = b ^ a = a ^ (a ^ b) = (a ^ a) ^ b = b;



