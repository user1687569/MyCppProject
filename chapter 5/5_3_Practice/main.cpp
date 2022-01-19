//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    int n;
    int sum = 0;

    do{
        std::cout << "Enter an integer: ";
        std::cin >> n;
        sum += n;
        std::cout << "Currently, sum is: " << sum << std::endl;
    }while(n != 0);

    std::cout << "Quit the game!" << std::endl;
    return 0;
}




