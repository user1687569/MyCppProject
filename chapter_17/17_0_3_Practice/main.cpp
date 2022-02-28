//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int n;
    std::cin >> n;

    std::cout << "n     n*n\n";
    std::cout << n << "     " << n * n << " (decimal)\n";

    std::cout << std::hex;
    std::cout << n << "     ";
    std::cout << n * n << " (hexadecimal)\n";

    std::cout << std::oct << n << "     " << n * n << " (octal)\n";

    dec(std::cout);
    std::cout << n << "     " << n * n << " (decimal)\n";

    return 0;
}


