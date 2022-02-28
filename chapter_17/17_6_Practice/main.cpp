//Copyright (c) 2022 user1687569
#include <iostream>
#include "emp.h"

inline void show_line(int n);
void show_menu();
inline void eatline();

const int MAX = 10;

int main()
{
    abstr_emp * pc[MAX];
    int ct = 0;

    std::string fname, lname, job, reportsto;
    int inchargeof;

    std::ifstream fin("out.txt", std::ios_base::in);
    if(fin.is_open())
    {
        int kind;
        while (fin >> kind)
        {
            switch (kind)
            {
            case Employee:
                fin >> fname;
                fin >> lname;
                fin >> job;
                pc[ct] = new employee(fname, lname, job);
                break;
            case Manager:
                fin >> fname;
                fin >> lname;
                fin >> job;
                fin >> inchargeof;
                pc[ct] = new manager(fname, lname, job, inchargeof);
                break;
            case Fink:
                fin >> fname;
                fin >> lname;
                fin >> job;
                fin >> reportsto;
                pc[ct] = new fink(fname, lname, job, reportsto);
                break;
            case Highfink:
                fin >> fname;
                fin >> lname;
                fin >> job;
                fin >> reportsto;
                fin >> inchargeof;
                pc[ct] = new highfink(fname, lname, job, reportsto, inchargeof);
                break;
            default:
                break;
            }
            ct++;
        }

        std::cout << "content in out.txt" << std::endl;
        for(int i = 0; i < ct; i++)
            pc[i]->ShowAll();
    }

    show_menu();
    char choice;
    abstr_emp * p;
    while (std::cin >> choice && choice != 'q' && ct < MAX)
    {
        /* code */
        eatline();
        switch (choice)
        {
        case 'a':
            p = new employee;
            p->SetAll();
            pc[ct] = p;
            break;
        case 'b':
            p = new manager;
            p->SetAll();
            pc[ct] = p;
            break;
        case 'c':
            p = new fink;
            p->SetAll();
            pc[ct] = p;
            break;
        case 'd':
            p = new highfink;
            p->SetAll();
            pc[ct] = p;
            break;
        default:
            break;
        }
        ct++;
        show_menu();
    }

    std::ofstream fout("out.txt", std::ios_base::out);
    for(int i = 0; i < ct; i++)
    {
        pc[i]->writeall(fout);
        fout << std::endl;
    }
    fout.close();

    std::cout << "content in array are written to out.txt" << std::endl;

    // free memories
    for(int i = 0; i < ct; i++)
        delete pc[i];

    return 0;
}


void show_menu()
{
    std::ios_base::fmtflags old_fmt = 
                std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    show_line(35);
    std::cout.width(20);
    std::cout << "a.employee";
    std::cout << "b.manager" << std::endl;
    std::cout.width(20);
    std::cout << "c.fink";
    std::cout << "d.highfink" << std::endl;
    std::cout << "q.quit" << std::endl;
    show_line(35);
    std::cout << "Select a type: " << std::endl;
    std::cout.setf(old_fmt);
}


inline void show_line(int n)
{
    std::cout.fill('-');
    std::cout.width(n);
    std::cout << "-" << std::endl;
    std::cout.fill(' ');
}


inline void eatline()
{
    while (std::cin.get() != '\n')
    {
        continue;
    }
}

