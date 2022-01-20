//Copyright (c) 2022 user1687569
#include <iostream>
#include <array>

const int arraySize = 101;

int main()
{
    int i;
    std::array<long double, arraySize> factorials;
    factorials[0] = factorials[1] = 1;
    
    for(i = 2; i < arraySize; i++)
        factorials[i] = i * factorials[i-1];
    
    for(i = 0; i < arraySize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;

    return 0;
}




