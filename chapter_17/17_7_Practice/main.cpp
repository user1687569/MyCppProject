//Copyright (c) 2022 user1687569
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "store.h"

void ShowStr(const std::string & str);
void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr);

int main()
{
    std::vector<std::string> vostr;
    std::string temp;

    // acquire strings
    std::cout << "Enter strings (empty line to quit): \n";
    while (getline(std::cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    std::cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);
    
    // store in a file
    std::ofstream fout("strings.dat", std::ios_base::out | std::ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // recover file contents
    std::vector<std::string> vistr;
    std::ifstream fin("strings.dat", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open())
    {
        std::cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);
    std::cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}


void ShowStr(const std::string & str)
{
    std::cout << str << std::endl;
}


void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr)
{
    std::size_t len;
    while (fin.read((char *)&len, sizeof(std::size_t)))
    {
        std::string str;
        char ch;
        for(int i = 0; i < len; i++)
        {
            fin.read(&ch, sizeof(char));
            str.push_back(ch);
        }
        vistr.push_back(str);
    }
}


