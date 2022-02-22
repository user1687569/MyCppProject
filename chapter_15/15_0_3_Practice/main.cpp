//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include "queuetp.h"


int main()
{
    QueueTP<std::string> cs(5);
    std::string temp;

    while (!cs.isfull())
    {
        std::cout << "Please enter your name. You will be "
                     "served in the order of arrival." << std::endl
                  << "name: ";
        std::getline(std::cin, temp);
        cs.enqueue(temp);
    }
    
    std::cout << "The queue is full. Processing begins!" << std::endl;

    while (!cs.isempty())
    {
        cs.dequeue(temp);
        std::cout << "Now processing " << temp << "..." << std::endl;
    }
    
    return 0;
}


