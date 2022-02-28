//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

const int LIM = 20;
struct planet
{
    char name[LIM];
    double population;
    double g;
};

const char * file = "planets.dat";
inline void eatline() { while (std::cin.get() != '\n') continue; }


int main(int argc, char * argv[])
{
    planet pl;
    std::cout << std::fixed << std::right;
    
    std::fstream finout;
    finout.open(file, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
    int ct = 0;
    if(finout.is_open())
    {
        finout.seekg(0);
        std::cout << "Here are the current contents of the "
                  << file << " file: " << std::endl;
        while (finout.read((char *) &pl, sizeof pl))
        {
            std::cout << ct++ << std::setw(LIM) << pl.name << ": "
                      << std::setprecision(0) << std::setw(12) << pl.population
                      << std::setprecision(2) << std::setw(12) << pl.g << std::endl;
        }
        if(finout.eof())
            finout.clear();
        else
        {
            std::cerr << "Error in reading " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        std::cerr << file << " could not be opened -- bye.\n";
        exit(EXIT_FAILURE);
    }

    // change a record
    std::cout << "Enter the record number you widh to change: ";
    long rec;
    std::cin >> rec;
    eatline();
    if(rec < 0 || rec >= ct)
    {
        std::cerr << "Invalid record number -- bye\n";
        exit(EXIT_FAILURE);
    }

    std::streampos place = rec * sizeof pl;
    finout.seekg(place);
    if(finout.fail())
    {
        std::cerr << "Error on attempted seek\n";
        exit(EXIT_FAILURE);
    }

    finout.read((char *) &pl, sizeof pl);
    std::cout << "Your selection:\n";
    std::cout << rec << ": " << std::setw(LIM) << pl.name << ": "
              << std::setprecision(0) << std::setw(12) << pl.population
              << std::setprecision(2) << std::setw(12) << pl.g << std::endl;
    if(finout.eof())
        finout.clear();
    
    std::cout << "Enter planet name: ";
    std::cin.get(pl.name, LIM);
    eatline();
    std::cout << "Enter planetary popultion: ";
    std::cin >> pl.population;
    std::cout << "Enter planet's acceleration of gravity: ";
    std::cin >> pl.g;
    finout.seekp(place);
    finout.write((char *) &pl, sizeof pl) << std::flush;
    if(finout.fail())
    {
        std::cerr << "Error on attempted write\n";
        exit(EXIT_FAILURE);
    }

    // show revised file
    ct = 0;
    finout.seekg(0);
    std::cout << "Here are the new contents of the " << file
              << " file:\n";
    while (finout.read((char *) &pl, sizeof pl))
    {
        std::cout << ct++ << std::setw(LIM) << pl.name << ": "
                      << std::setprecision(0) << std::setw(12) << pl.population
                      << std::setprecision(2) << std::setw(12) << pl.g << std::endl;
    }
    finout.close();
    std::cout << "Done.\n";

    return 0;
}


