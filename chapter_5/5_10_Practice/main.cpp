//Copyright (c) 2022 user1687569
#include <iostream>

int main()
{
    int i, j;
    int rows;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    for(i = 0; i < rows; i++)
    {   
        for(j = 1; j < rows - i; j++)
        {
            std::cout << '.' << ' ';
        }
        for(j = 0; j < i + 1; j++)
        {
            std::cout << '*' << ' ';
        }

        std::cout << std::endl;
    }

    return 0;
}




