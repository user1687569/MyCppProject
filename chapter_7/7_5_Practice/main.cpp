//Copyright (c) 2022 user1687569
#include <iostream>

long long factorial(unsigned number);

int main()
{
    unsigned num;
    long long result = 0LL;

    std::cout << "Please enter one integer: ";
    std::cin >> num;

    result = factorial(num);
    std::cout << num << "! = " << result << std::endl;
    return 0;
}


long long factorial(unsigned number)
{
    long long result = 1LL;
    if(number == 0)
        result *= 1;
    else
        result = number * factorial(number-1);

    return result;
}

