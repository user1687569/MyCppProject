//Copyright (c) 2022 user1687569
#include <iostream>
#include <iomanip>
#include <cmath>


int main()
{
    std::cout << std::fixed << std::right;
    std::cout << std::setw(6) << "N" << std::setw(14)
              << "square root" << std::setw(15)
              << "fourth root\n";
    double root;
    for(int n = 10; n <= 100; n += 10)
    {
        root = sqrt(double(n));
        std::cout << std::setw(6) << std::setfill('.') << n 
                  << std::setfill(' ') << std::setw(12) << std::setprecision(3) << root
                  << std::setw(14) << std::setprecision(4) << sqrt(root)
                  << std::endl;
    }    

    std::setprecision(2);
    std::setw(10);
    std::cout << 6.33432  << std::setw(10) << 6.333423 << std::endl;
    std::cout << 6.333 << 6.2323 <<std::endl;
    return 0;
}


