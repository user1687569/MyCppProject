//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>

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
    bool noneFlag;
    
    std::cout << "Please input number of patrons: ";   
    std::cin >> num;

    patron *patronList = new patron[num];
    for(i = 0; i < num; i++)
    {
        std::cout << "Enter number " << i + 1 << " patron name: ";
        std::cin.sync();        //clear buffer
        std::getline(std::cin, patronList[i].name);
        std::cout << "Enter number " << i + 1 << " patron donation: ";
        std::cin >> patronList[i].donation;
    }

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



