//Copyright (c) 2022 user1687569
#include <iostream>
#include <cmath>

int main()
{
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::cout.setf(std::ios_base::showpos);
    std::cout.setf(std::ios_base::showpoint);
    std::cout.precision(3);

    std::ios_base::fmtflags old = std::cout.setf(std::ios_base::scientific,
                                                 std::ios_base::floatfield);
    std::cout << "Left Justification: " << std::endl;
    long n;
    for(n = 1; n <= 41; n += 10)
    {
        std::cout.width(4);
        std::cout << n << "|";
        std::cout.width(12);
        std::cout << sqrt(double(n)) << "|\n";
    }

    // change to internal justification
    std::cout.setf(std::ios_base::internal, std::ios_base::adjustfield);
    
    // restore default floating-point display style
    std::cout.setf(old, std::ios_base::floatfield);

    std::cout << "Internal Justification: " << std::endl;
    for(n = 1; n <= 41; n += 10)
    {
        std::cout.width(4);
        std::cout << n << "|";
        std::cout.width(12);
        std::cout << sqrt(double(n)) << "|\n";
    }

    std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout << "Right Justification:\n";
    for(n = 1; n <= 41; n += 10)
    {
        std::cout.width(4);
        std::cout << n << "|";
        std::cout.width(12);
        std::cout << sqrt(double(n)) << "|\n";
    }

    return 0;
}


// Left Justification:
// +1  |+1.000e+000 |
// +11 |+3.317e+000 |
// +21 |+4.583e+000 |
// +31 |+5.568e+000 |
// +41 |+6.403e+000 |
// Internal Justification:
// +  1|+       1.00|
// + 11|+       3.32|
// + 21|+       4.58|
// + 31|+       5.57|
// + 41|+       6.40|
// Right Justification:
//   +1|      +1.000|
//  +11|      +3.317|
//  +21|      +4.583|
//  +31|      +5.568|
//  +41|      +6.403|

