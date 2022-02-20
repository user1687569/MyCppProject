//Copyright (c) 2022 user1687569
#include <iostream>
#include "worker.h"

Worker::~Worker() {}

void Worker::Set()
{
    std::cout << "Enter worker's name: ";
    getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n')
        continue;
}


void Worker::Show() const
{
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}


void Waiter::Set()
{
    Worker::Set();
    std::cout << "Enter waiter's panache rating: ";
    std::cin >> panache;
    while (std::cin.get() != '\n')
        continue;
}


void Waiter::Show() const
{
    std::cout << "Category: waiter" << std::endl;
    Worker::Show();
    std::cout << "Panache rating: " << panache << std::endl;
}


char * Singer::pv[] = {"other", "alto", "contralto",
                "soprano", "bass", "baritone", "tenor"};


void Singer::Set()
{
    Worker::Set();
    std::cout << "Enter number for singer's vocal range: " << std::endl;
    int i;
    for(i = 0; i < Vtypes; i++)
    {
        std::cout << i << ": " << pv[i] << "  ";
        if(i % 4 == 3)
            std::cout << std::endl;
    }

    if(i % 4 != 0)
        std::cout << std::endl;

    while(std::cin >> voice && (voice < 0 || voice >= Vtypes))
        std::cout << "Please enter a value >= 0 and <" << Vtypes << std::endl;
    
    while (std::cin.get() != '\n')
        continue;
}


void Singer::Show() const
{
    std::cout << "Category: singer" << std::endl;
    Worker::Show();
    std::cout << "Vocal range: " << pv[voice] << std::endl;
}


