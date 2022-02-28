//Copyright (c) 2022 user1687569
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const char * file = "guests.txt";

int main(int argc, char * argv[])
{
    char ch;
    std::ifstream fin;
    fin.open(file);

    if(fin.is_open())
    {
        std::cout << "Here are the current contents of the "
                  << file << " file: " << std::endl;
        while (fin.get(ch))
            std::cout << ch;
        fin.close();
    }

    // add new names
    std::ofstream fout(file, std::ios_base::out | std::ios::app);
    if(!fout.is_open())
    {
        std::cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter guest names (enter a blank line to quit):\n";
    std::string name;
    while (getline(std::cin, name) && name.size() > 0)
    {
        fout << name << std::endl;
    }
    fout.close();
    
    // show revised file
    fin.clear();
    fin.open(file);
    if(fin.is_open())
    {
        std::cout << "Here are the new contents of the " 
                  << file << " file:\n";
        while (fin.get(ch))
        {
            std::cout << ch;
        }
        fin.close();
    }

    std::cout << "Done." << std::endl;
    return 0;
}


