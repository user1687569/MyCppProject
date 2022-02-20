//Copyright (c) 2022 user1687569
#include <iostream>
#include <ctime>
#include "emp.h"

abstr_emp::abstr_emp() : fname("Blockchain"), lname("Lee"), job("Programmer")
{}


abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
    : fname(fn), lname(ln), job(j)
{}


abstr_emp::~abstr_emp()
{}


void abstr_emp::ShowAll() const
{
    std::cout << "Name: "<< fname << " " << lname << std::endl;
    std::cout << "Job: " << job << std::endl;
}


void abstr_emp::SetAll()
{
    std::cin.clear();
    while(std::cin.get() != '\n')
        continue;
    std::cout << "Enter first name: ";
    std::getline(std::cin, fname);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job); 
}


std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << "Name: " << e.fname << " " << e.lname << std::endl;
    os << "Job: " << e.job << std::endl;
    return os;
}


// ######
// employee method
employee::employee() {}


void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}


void employee::SetAll()
{
    abstr_emp::SetAll();
}


// ######
// manager method
manager::manager(const manager & m)
    : abstr_emp(m)
{
    inchargeof = m.inchargeof;
}


void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << inchargeof << std::endl;
}


void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter in charge of: " << std::endl;
    while (!(std::cin >> inchargeof))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
    }
}


// ######
// fink method
fink::fink(const fink & f)
    : abstr_emp(f)
{
    reportsto = f.reportsto;
}


void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Reports to: " << reportsto << std::endl;
}


void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter Reports to: " << std::endl;
    std::getline(std::cin, reportsto);
}


void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << manager::InChargeOf() << std::endl;
    std::cout << "Reports to: " << fink::ReportsTo() << std::endl;
}


void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, fink::ReportsTo());
    std::cout << "Enter Inchargeof: ";
    std::cin >> manager::InChargeOf();
    std::cin.get();
}








