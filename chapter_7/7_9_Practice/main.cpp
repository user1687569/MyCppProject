//Copyright (c) 2022 user1687569
#include <iostream>
#include <cstring>

const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    std::cout << "Enter class size: ";
    int class_size;
    std::cin >> class_size;
    while(std::cin.get() != '\n')
        continue;

    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for(int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }

    display3(ptr_stu, entered);
    delete [] ptr_stu;
    std::cout << "Done" << std::endl;
    return 0;
}


int getinfo(student pa[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        std::cout << "Enter student " << (i + 1) << " fullname: ";
        std::cin.getline(pa[i].fullname, SLEN);
        if(strlen(pa[i].fullname) == 0)
        {
            std::cout << "Full name can not be empty, terminate input!" << std::endl;
            break;
        }
        std::cout << "Enter student " << (i + 1) << " hobby: ";
        std::cin.getline(pa[i].hobby, SLEN);
        std::cout << "Enter student " << (i + 1) << " ooplevel: ";
        (std::cin >> pa[i].ooplevel).get();
    }

    return i;
}


void display1(student st)
{
    std::cout << "Student Fullname: " << st.fullname << "; ";
    std::cout << "Hobby: " << st.hobby << "; ";
    std::cout << "OopLevel: " << st.ooplevel << std::endl;
}


void display2(const student * ps)
{
    std::cout << "Student Fullname: " << ps->fullname << "; ";
    std::cout << "Hobby: " << ps->hobby << "; ";
    std::cout << "OopLevel: " << ps->ooplevel << std::endl;
}


void display3(const student pa[], int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << "Student Fullname: " << pa[i].fullname << "; ";
        std::cout << "Hobby: " << pa[i].hobby << "; ";
        std::cout << "OopLevel: " << pa[i].ooplevel << std::endl;
    }
}

