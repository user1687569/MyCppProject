//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

struct patron
{   
    std::string name;
    double donation;
};

int main()
{
    int i;
    int num;
    int numOfGrandPatrons = 0;
    int numOfNormalPatrons = 0;
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

    inFile >> num;
    inFile.get();   //Next line
    std::cout << "num = " << num << std::endl;
    patron *patronList = new patron[num];
    for(i = 0; i < num; i++)
    {
        std::getline(inFile, patronList[i].name);
        inFile >> patronList[i].donation;
        inFile.get();   //Next line
    }

    inFile.close();

    //Show grand patrons information
    std::cout << std::endl << "Grand Patrons: " << std::endl;
    for(i = 0; i < num; i++)
    {
        if(patronList[i].donation >= 10000)
        {
            numOfGrandPatrons++;
            std::cout << patronList[i].name << std::endl;
        }
    }

    if(numOfGrandPatrons == 0)
        std::cout << "none" << std::endl;
    
    //Show normal patrons information
    std::cout << std::endl << "Patrons: " << std::endl;
    for(i = 0; i < num; i++)
    {
        if(patronList[i].donation < 10000)
        {
            numOfNormalPatrons++;
            std::cout << patronList[i].name << std::endl;
        }
    }

    if(numOfNormalPatrons == 0)
        std::cout << "none" << std::endl;

    return 0;
}



