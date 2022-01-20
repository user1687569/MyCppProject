//Copyright (c) 2022 user1687569
#include <iostream>
#include <climits>


int main()
{
    const int conversionFactor = 12;
    int inch;
    std::cout << "Please input your height (unit: inch):_";
    std::cin >> inch;
    std::cout << "You height is " << inch / conversionFactor;
    std::cout << " foot and " << inch % conversionFactor << " inches."; 
    return 0;
}

