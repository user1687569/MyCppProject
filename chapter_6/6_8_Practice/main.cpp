//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main()
{   
    std::string fileName;
    std::ifstream inFile;

    std::cout << "Enter name of data file: ";
    std::getline(std::cin, fileName);
    inFile.open(fileName);
    if(!inFile.is_open())
    {
        std::cout << "Could not open the file " << fileName << std::endl;
        std::cout << "Program terminating." << std::endl;
        exit(EXIT_FAILURE);
    }

    char c;
    int count = 0;

    inFile >> c;
    while (inFile.good())
    {
        count += 1;
        inFile >> c;
    }

    if(inFile.eof())
        std::cout << "End of file reached." << std::endl;
    else if(inFile.fail())
        std::cout << "Input terminated by data mismatch." << std::endl;
    else 
        std::cout << "Input terminated for unknown reason." << std::endl;
    
    if(count == 0)
        std::cout << "No data processed." << std::endl;
    else
    {
        std::cout << "There are " << count << " characters in " << fileName << std::endl; 
    }
    
    inFile.close();
    
    return 0;
}



