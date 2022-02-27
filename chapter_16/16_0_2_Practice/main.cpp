//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


int main()
{
    std::ifstream fin;
    fin.open("tobuy2.txt");
    if(fin.is_open() == false)
    {
        std::cerr << "Can't open file. Bye" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string item;
    int count = 0;
    // std::getline(fin, item, ':');
    std::getline(fin, item);
    while (fin)
    {
        ++count;
        std::cout << count << ": " << item << std::endl;
        // std::getline(fin, item, ':');
        std::getline(fin, item);
    }

    std::cout << "Done" << std::endl;
    fin.close();
    return 0;
}



