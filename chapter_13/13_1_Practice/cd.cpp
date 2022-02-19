//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "cd.h"


Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}


Cd::Cd(char * s1, char * s2, int n, double x)
{
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}


Cd::Cd(const Cd & d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}


Cd::~Cd()
{
}


void Cd::Report() const
{
    std::cout << "Performer: " << performers << std::endl;
    std::cout << "    Label: " << label << std::endl;
    std::cout << "Selection: " << selections << std::endl;
    std::cout << " Playtime: " << playtime << std::endl << std::endl;
}


Cd & Cd::operator=(const Cd & d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}


Classic::Classic() : Cd()
{
    cdInfo[0] = '\0';
}


Classic::Classic(char * info, char * s1, char * s2, int n, double x)
    : Cd(s1, s2, n, x)
{
    strcpy(cdInfo, info);
}


Classic::Classic(char * info, const Cd & d)
    : Cd(d)
{
    strcpy(cdInfo, info);
}


Classic::~Classic()
{
}


void Classic::Report() const
{
    std::cout << "     Info: " << cdInfo << std::endl;
    Cd::Report();
}


Classic & Classic::operator=(const Classic & classicCd)
{
    if(this == &classicCd)
        return *this;
    Cd::operator=(classicCd);
    
    strcpy(cdInfo, classicCd.cdInfo);
    return *this;
}

