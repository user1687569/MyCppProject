//Copyright (c) 2022 user1687569
#include <iostream>


int main()
{
    std::cout << "Enter numbers: ";

    int sum = 0;
    int input;
    // 输入与 预期格式不匹配反过来将导致表达式 cin >> input的结果为false
    while (std::cin >> input)
    {
        sum += input;
    }

    std::cout << "Last value entered = " << input << std::endl;
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}


