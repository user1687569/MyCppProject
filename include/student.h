// Copyright (c) 2022 user1687569
#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student
{
    public:
    Student(int age, std::string name);
    void setAge(int age);
    void setName(std::string name);
    int getAge();
    std::string getName();
    void showInfo(); 

    private:
        int m_age;
        std::string m_name;
};



#endif
