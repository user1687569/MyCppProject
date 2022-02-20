//Copyright (c) 2022 user1687569
#include <iostream>
#include "worker.h"


Worker::~Worker() {}

// protected method
void Worker::Data() const
{
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}


// protected method
void Worker::Get()
{
    getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n')
        continue;
}


//###### Waiter methods
// protected method
void Waiter::Data() const
{
    std::cout << "Panache rating: " << panache << std::endl;
}


// protected method
void Waiter::Get()
{
    std::cout << "Enter waiter's panache rating: ";
    std::cin >> panache;
    while (std::cin.get() != '\n')
        continue;    
}


void Waiter::Set()
{
    std::cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}


void Waiter::Show() const
{
    std::cout << "Catagory: waiter" << std::endl;
    Worker::Data();
    Data();
}


// ###### Singer methods
char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto",
                    "soprano", "bass", "baritone", "tenor"};

// protected method
void Singer::Data() const
{
    std::cout << "Vocal range: " << pv[voice] << std::endl;
}


// protected method
void Singer::Get()
{
    std::cout << "Enter number for singer's vocal range: " << std::endl;
    int i;
    for(i = 0; i < Vtypes; i++)
    {
        std::cout << i << ": " << pv[i] << "   ";
        if(i % 4 == 3)
            std::cout << std::endl;
    }
    if(i % 4 != 0)
        std::cout << std::endl;
    
    std::cin >> voice;
    while (std::cin.get() != '\n')
        continue;
}


void Singer::Set()
{
    std::cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}


void Singer::Show() const
{
    std::cout << "Category: singer" << std::endl;
    Worker::Data();
    Data();
}


//###### SingerWaiter methods
// protected method
void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}


// protected method
void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}


void SingingWaiter::Set()
{
    std::cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}


void SingingWaiter::Show() const
{
    std::cout << "Category: singing waiter" << std::endl;
    Worker::Data();
    Data();
}

