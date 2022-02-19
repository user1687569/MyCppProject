//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "string.h"

const int ArSize = 10;
const int MaxLen = 81;


int main()
{   
    std::ofstream outFile;
    outFile.open("sayingsText.txt");
    String name;
    std::cout << "Hi, what's your name?" << std::endl << "<<";
    outFile << "Hi, what's your name?" << std::endl << "<<";
    std::cin >> name;

    std::cout << name << ", please enter up to " << ArSize 
              << " short sayings <empty line to quit>: " << std::endl;
    outFile   << name << ", please enter up to " << ArSize 
              << " short sayings <empty line to quit>: " << std::endl;
    
    String sayings[ArSize];
    char temp[MaxLen];
    int i;

    for(i = 0; i < ArSize; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin.get(temp, MaxLen);
        while (std::cin && std::cin.get() != '\n')
            continue;
        
        if(!std::cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }

    int total = i;
    if(total > 0)
    {
        std::cout << "Here are your sayings: " << std::endl;
        outFile << "Here are your sayings: " << std::endl;
        for(i = 0; i < total; i++)
        {
            std::cout << sayings[i][0] << ": " << sayings[i] << std::endl;
            outFile << sayings[i][0] << ": " << sayings[i] << std::endl;
        }

        // int shortest = 0;
        // int first = 0;
        String * shortest = &sayings[0];
        String * first = &sayings[0];
        for(i = 1; i < total; i++)
        {
            // if(sayings[i].length() < sayings[shortest].length())
            //     shortest = i;
            // if(sayings[i] < sayings[first])
            //     first = i;
            if(sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if(sayings[i] < *first)
                first = &sayings[i];
        }

        // std::cout << "Shortest saying: " << std::endl << sayings[shortest] << std::endl;
        // std::cout << "First alphabetically: " << std::endl << sayings[first] << std::endl;
        // std::cout << "This program used " << String::HowMany() << " String objects. Bye." << std::endl;
        // outFile << "Shortest saying: " << std::endl << sayings[shortest] << std::endl;
        // outFile << "First alphabetically: " << std::endl << sayings[first] << std::endl;
        // outFile << "This program used " << String::HowMany() << " String objects. Bye." << std::endl;

        std::cout << "Shortest saying: " << std::endl << *shortest << std::endl;
        std::cout << "First alphabetically: " << std::endl << *first << std::endl;
        std::cout << "This program used " << String::HowMany() << " String objects. Bye." << std::endl;
        outFile << "Shortest saying: " << std::endl << *shortest << std::endl;
        outFile << "First alphabetically: " << std::endl << *first << std::endl;
        outFile << "This program used " << String::HowMany() << " String objects. Bye." << std::endl;

        srand(time(0));
        int choice = rand() % total;
        String * favorite = new String(sayings[choice]);
        std::cout << "My favorite saying: " << std::endl << *favorite << std::endl;
        outFile   << "My favorite saying: " << std::endl << *favorite << std::endl;
        delete favorite;
    }
    else
    {
        std::cout << "No input! Bye." << std::endl;
        outFile << "No input! Bye." << std::endl;
    }

    return 0;
}



