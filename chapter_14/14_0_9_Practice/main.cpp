//Copyright (c) 2022 user1687569
#include <iostream>
#include "tempmemb.h"


int main()
{
    Beta<double> guy(3.5, 3);
    std::cout << "T was set to double" << std::endl;
    guy.Show();

    std::cout << "V was set to T, which is double, then V was set to int" << std::endl;

    std::cout << guy.Blab(10, 2.3) << std::endl;
    std::cout << "U was set to int" << std::endl;

    std::cout << guy.Blab(10.0, 2.3) << std::endl;
    std::cout << "U was set to double" << std::endl;
    std::cout << "Done" << std::endl;
    
    return 0;
}


