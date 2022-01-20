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
        if(i != rows - 1)
        {
            for(j = 0; j < rows - i; j++)
                std::cout << '.' << ' ';
            
            for(j = 0; j < i; j++)
                std::cout << '*' << ' ';
        }
        else
        {
            for(j = 0; j < rows; j++)
                std::cout << '*' << ' ';
        }
        
        std::cout << std::endl;
    }

    return 0;
}




