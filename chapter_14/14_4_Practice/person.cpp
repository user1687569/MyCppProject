//Copyright (c) 2022 user1687569
#include <iostream>
#include <ctime>
#include "person.h"


Person::~Person() {}

// protected method
void Person::Data() const
{
    std::cout << "First Name: " << firstname << std::endl;
    std::cout << " Last Name: " << lastname << std::endl;
}


// protected method
void Person::Get()
{
    std::cout << "Enter first name: ";
    getline(std::cin, firstname);
    std::cout << "Enter last name: ";
    getline(std::cin, lastname);
}


//###### Gunslinger methods
// protected method
void Gunslinger::Data() const
{
    std::cout << "Draw time: " << drawtime << std::endl;
    std::cout << "Gun nicks: " << gunsNick << std::endl;
}


// protected method
void Gunslinger::Get()
{
    std::cout << "Enter Gunslinger's draw time: ";
    while (!(std::cin >> drawtime))
    {
        std::cin.clear();
        while(std::cin.get() != '\n')
            continue;
        std::cout << "Bad input, please enter a number: ";
    }
    
    std::cout << "Enter Gunslinger's guns nick: ";
    while (!(std::cin >> gunsNick))
    {
        std::cin.clear();
        while(std::cin.get() != '\n')
            continue;
        std::cout << "Bad input, please enter a number: ";
    }
}


void Gunslinger::Set()
{
    std::cout << "Enter Gunslinger's name: ";
    Person::Get();
    Get();
}


void Gunslinger::Show() const
{
    std::cout << "Catagory: Gunslinger" << std::endl;
    Person::Data();
    Data();
}


// ###### PokerPlayer methods
// protected method
void PokerPlayer::Data() const
{
    std::cout << "Card number: " << cardNum << std::endl;
}


// protected method
void PokerPlayer::Get()
{
    // std::cout << "Enter PokerPlayer's card number: " << std::endl;
    // while (!(std::cin >> cardNum))
    // {
    //     std::cin.clear();
    //     while(std::cin.get() != '\n')
    //         continue;
    //     std::cout << "Bad input, please enter a number: ";
    // }
    srand(time(0));
    cardNum = (rand() % 52) + 1;
}


void PokerPlayer::Set()
{
    std::cout << "Enter PokerPlayer's name: ";
    Person::Get();
    Get();
}


void PokerPlayer::Show() const
{
    std::cout << "Category: PokerPlayer" << std::endl;
    Person::Data();
    Data();
}


//###### BadDude methods
// protected method
void BadDude::Data() const
{
    Gunslinger::Data();
    PokerPlayer::Data();
}


// protected method
void BadDude::Get()
{
    Gunslinger::Get();
    PokerPlayer::Get();
}


void BadDude::Set()
{
    std::cout << "Enter singing Gunslinger's name: ";
    Person::Get();
    Get();
}


void BadDude::Show() const
{
    std::cout << "Category: singing Gunslinger" << std::endl;
    Person::Data();
    Data();
}

