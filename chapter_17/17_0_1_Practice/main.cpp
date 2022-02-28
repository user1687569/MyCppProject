//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>

int main()
{
    const char * state1 = "Florida";
    const char * state2 = "Kansas";
    const char * state3 = "Euphoria";

    int len = std::strlen(state2);
    std::cout << "Increasing loop index: " << std::endl;

    int i;
    for(i = 1; i <= len; i++)
    {
        std::cout.write(state2, i);
        std::cout << std::endl;
    }

    std::cout << "Decreading loop index: " << std::endl;
    for(i = len; i > 0; i--)
        std::cout.write(state2, i) << std::endl;

    std::cout << "Exceeding string length: " << std::endl;
    std::cout.write(state2, len + 5) << std::endl;

    return 0;
}


// Increasing loop index: 
// K
// Ka
// Kan
// Kans
// Kansa
// Kansas
// Decreading loop index:
// Kansas
// Kansa
// Kans
// Kan
// Ka
// K
// Exceeding string length:
// KansasEuph

