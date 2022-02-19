//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>
#include "cd.h"

Cd::Cd()
{
    performers = nullptr;
    label = nullptr;
    selections = 0;
    playtime = 0.0;
}


Cd::Cd(char * s1, char * s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}


Cd::Cd(const Cd & d)
{
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);

    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}


Cd::~Cd()
{
    delete [] performers;
    delete [] label;
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
    delete [] performers;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);

    delete [] label;
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}


Classic::Classic() : Cd()
{
    cdInfo = nullptr;
}


Classic::Classic(char * info, char * s1, char * s2, int n, double x)
    : Cd(s1, s2, n, x)
{
    cdInfo = new char[strlen(info) + 1];
    strcpy(cdInfo, info);
}


Classic::Classic(char * info, const Cd & d)
    : Cd(d)
{
    cdInfo = new char[strlen(info) + 1];
    strcpy(cdInfo, info);
}


Classic::~Classic()
{
    delete [] cdInfo;
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
    
    delete [] cdInfo;
    cdInfo = new char[strlen(classicCd.cdInfo)];
    strcpy(cdInfo, classicCd.cdInfo);
    return *this;
}

