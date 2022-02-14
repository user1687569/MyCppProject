//Copyright (c) 2022 user1687569
#include <iostream>
#include <string>
#include <cstring>
#include "plorg.h"


Plorg::Plorg(const int ci, const char * name)
{
    m_CI = ci;
    strncpy(m_name, name, Len);
}


void Plorg::setCi(const int ci)
{
    m_CI = ci;
}


void Plorg::showPlorg() const
{
    std::cout << "Plorg Name: [" << m_name 
              << "] CI: [" << m_CI << "]" << std::endl;
}

