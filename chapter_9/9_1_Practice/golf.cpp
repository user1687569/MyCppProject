//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}


int setgolf(golf &g)
{
    int result = 0;
    std::cout << "Enter golf name: ";
    std::cin.getline(g.fullname, Len);
    if(strlen(g.fullname) != 0)
        result = 1;

    std::cout << "Enter golf handicap: ";
    std::cin >> g.handicap;

    return result;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}


void showgolf(const golf &g)
{
    std::cout << "Golf fullname: " << g.fullname << ", handicap: " << g.handicap << std::endl;
}


