//Copyright (c) 2022 user1687569
#include "header.h"

Student::Student(int age, std::string name)
{
    m_age = age;
    m_name = name;
}

void Student::showInfo()
{
    std::cout << "Student Name: " << m_name << std::endl;
    std::cout << "Student Age: " << m_age << std::endl;
}


