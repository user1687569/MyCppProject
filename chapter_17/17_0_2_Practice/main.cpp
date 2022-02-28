//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    std::cout << "12345678901234567890\n";
    char ch = 'K';
    int t = 273;
    std::cout << ch << ":\n";
    std::cout << t << ":\n";
    std::cout << -t << ":\n";

    double f1 = 1.200;
    std::cout << f1 << ":\n";
    std::cout << (f1 + 1.0 / 9.0) << ":\n";

    double f2 = 1.67E2;
    std::cout << f2 << ":\n";
    f2 += 1.0 / 9.0;
    std::cout << f2 << ":\n";
    std::cout << (f2 * 1.0e4) << ":\n";

    double f3 = 2.3e-4;
    std::cout << f3 << ":\n";
    std::cout << f3 / 10 << ":\n";

    return 0;
}


