//Copyright (c) 2022 user1687569
#include <iostream>

void showMenu();
void displayByName();
void displayByTitle();
void displayByBopname();
void displayByPreference();
void defaultCase();

const int memberSize = 5;
const int strsize = 30;

struct bop
{
    char fullname[strsize];     //real name    
    char title[strsize];        //job title   
    char bopname[strsize];      //secret BOP name
    int preference;             //0 = fullname, 1 = title, 2 = bopname
};

bop bopMembers[5] = 
    {
        {"Wimp Macho", "Senior Programmer", "Satoshi", 0},
        {"Raki Rhodes", "Junior Programmer", "Bull", 1},
        {"Celia Laiter", "Intermediate Programmer", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "Pony", 1},
        {"Pat Hand", "C++ Programmer", "LOOPY", 2}
    };


int main()
{
    char ch;

    showMenu();
    std::cout << "Enter your choice: ";
    std::cin >> ch;

    while (ch != 'q')
    {
        switch (ch)
        {
        case 'a':
            displayByName();
            break;
        case 'b':
            displayByTitle();
            break;
        case 'c':
            displayByBopname();
            break;
        case 'd':
            displayByPreference();
            break;
        default:
            defaultCase();
            break;
        }
        // showMenu();
        std::cout << "Next choice: ";
        std::cin >> ch;
    }
    
    std::cout << "Byebye!" << std::endl;
    return 0;
}

void showMenu()
{
    std::cout << "Benevolent Order of Programmers Report: \n"
                 "a) display by name     b) display by title\n"
                 "c) display bu bopname  d) display by preference\n"
                 "q) quit\n";
}

void displayByName()
{
    int i;
    for(i = 0; i < memberSize; i++)
    {
        std::cout << bopMembers[i].fullname << std::endl;
    }
}

void displayByTitle()
{
    int i;
    for(i = 0; i < memberSize; i++)
    {
        std::cout << bopMembers[i].title << std::endl;
    }
}

void displayByBopname()
{
    int i;
    for(i = 0; i < memberSize; i++)
    {
        std::cout << bopMembers[i].bopname << std::endl;
    }
}

void displayByPreference()
{
    int i;
    for(i = 0; i < memberSize; i++)
    {
        switch (bopMembers[i].preference)
        {
        case 0:
            std::cout << bopMembers[i].fullname << std::endl;
            break;
        case 1:
            std::cout << bopMembers[i].title << std::endl;
            break;
        case 2:
            std::cout << bopMembers[i].bopname << std::endl;
            break;
        default:
            std::cout << "Preference is anbiguous." << std::endl;
            break;
        }
    }
}

void defaultCase()
{
    std::cout << "[Warning]Please enter character: a, b, c, d: " << std::endl;
}


